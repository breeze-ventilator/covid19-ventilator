/*
 * Hey everyone this is the main code for the ventilator. The ventilator will have the brain here
 *
 * It will get signals from the pi and send signals back to make sure everything is ok at a certain frequency
 * To make sure everything is legit at the begining of the loop we generate an aray  of 0s
 * every critical function will set one of the 0 to a 1 and at the end of the loop we will send it to the pi to show its funcitoning as intended
 *
 * Similarly the pi will send info over and we will read that to see that everything is good
 *
 * The arduino only directly controls the blower and 2 valves plus an alarm (and maybe a relay for power managment)
 *
 * It monitors all sensors (pressure, flow, fan rpm, battery voltage)
 *
 *
 * 1 = good, 0 = bad
 */

#include <Servo.h>
#include <Stepper.h>
#include <math.h> // TODO: only used in utilities.c, do we still need it here?
#include "pi.h"
#include "init.h"
#include "utilities.h"
#include "sensors.h"
#include "controls.c"
#include "comms.h"

// 8 kBytes of sRAM, 4 kBytes of eepROM, 256 kBytes of code storage
// (eepRom: for bootup, a read-only memory whose contents can be erased and reprogrammed using a pulsed voltage.)

// read at 500 Hz, send to screen at 10 Hz (info from 50 datapoints each time)

/* pid updated every n (n=5?) datapoints:
  - proportional: average over last n (configurable) datapoints
  - derivative: linear fit over n values, where each value is an average of n datapoints (needs last n**2 datapoints)
*/

unsigned long lastFlowReadTime;
unsigned long lastPresReadTime;
unsigned long currentTime;

// Data storage arrays, TODO: we could move them to init.h or init.c, or something?
int flowArray[NUM_OF_FLOW_MEASUREMENTS]; // macro defined in init.h
int pressureArray[NUM_OF_PRESSURE_MEASUREMENTS]; // assuming same number as measurement array

int avgFlowArray[NUM_OF_FLOW_MEASUREMENTS];
int avgPressureArray[NUM_OF_PRESSURE_MEASUREMENTS];

int pressureDataCount = 0;  // data storage index, for iterating through storage arrays
int flowDataCount = 0;    // same

int avgPressureCount = 0; // count to keep track of the PID's averaging arrays
int avgFlowCount = 0;

int blockingFlowReadings = 0; // Needed for asynchronous measurement taking
int blockingPresReadings = 0;

struct parameters {
  String mode;    // TODO: For parsing, it would be simpler to set mode to be an int
  int fiO2;
  int inspiratoryTime;
  int expiratoryTime;
  int peakInspiratoryPressure;
  int peakExpiratoryPressure;
  int sensitivity;
  
  struct alarms {
    int highPressureBound;
    int lowPressureBound;

    int highMinuteVentilationBound;
    int lowMinuteVentilationBound;
  }
};// struct parameters

struct parameters currentParams;
struct parameters newParams;

/*
  On startup, initializes pins and ensures Pi sends message.

  On failure, hangs forever.
*/
void setup() {
  initializePins();
  bool servosConnected = initializeServos();
  bool stepperConnected = initializeStepperMotor(); // needs a timeout
  bool piConnected = initializePiCommunication(PI_MAX_WAIT_TIME); 

  if (piConnected && servosConnected && stepperConnected) {
    turnOffAlarms();
    currentTime = millis(); 
    lastFlowReadTime = currentTime;
    lastPresReadTime = currentTime;
  }
  else {
    keepAlarmRingingForever();
}

/*
  Main Loop
*/

/*
  PseudoCode:
  
  vars:
    newParams: - contains new parameters to run
    currentParams: - contains currently running parameters (updates to new-params after every breath cycle)

  loop:
    # Setting Parameters
      if there is data read data from pi
        sets newParams;
    # Get Sensor readings
    if not in SETUP:
      # PID
    
    # If 200 ms have gone by, send
    
*/
void loop() {
  // ===== Check for Params =====
  if (Serial.available()) {
    String receivedString = Serial.readStringUntil("\n"); // reads up-to-but-not-including '\n' char
    setNewParameters(receivedString, *newParams);
  }


  //we will re-set system time every breath cycle is complete and when this happens we will let the pi know so that it can check breaths per minute

 
  // ===== Take readings ====
  currentTime = millis();
  if( ((currentTime - lastPresReadTime) >= PRES_READ_RATE) && (!blockingPresReadings)  ) {
    getFlowReading();
  }
  currentTime = millis();
  if( ((currentTime - lastFlowReadTime) >= FLOW_READ_RATE)&& (!blockingFlowReadings)  ){
    getPressureReading();
  }

  // ===== Breathing cycle ====

  // == Check for patient breath (change in airflow)
 
  if (mode == controlled) //TODO: this is psuedocode
    if inhale{
      controlledInhalation();
    }
    if exhale{  // TODO: This is probably isn't needed, as the fan shuts off and the patient exhales on their own, right?
      exhalation();
    }
 else if (mode == spontaneous){  //TODO: this is psuedocode for breath triggered

    int inhale = checkForFlow(); // check the flow sensor for delta-flow

    if inhale{
      controlledInhalation();
    }
    else if exhale{  // TODO: This is probably isn't needed, as the fan shuts off and the patient exhales on their own, right?
      exhalation();
    }
 }

  if(mode == patientTriggered){//if in patient triggered mode look for breath attempt?
    resetSystemTime(); // @ALL: is system time a thing? Is it for making sure we get a minimum # of breaths per minute?
  }
  //  setPressure(inhalePressure);


  sendAlarm(alarmMessage); //send the alarm to the pi    @ALL: why is this placed here?
  while (systemTime < howLongIWantToWait){
    waitForConfirmation();
  }

  //====== Update PID ======
  // TODO: This example may be all we need to start? https://playground.arduino.cc/Code/PIDLibaryBasicExample/
  // Do we need more than one of these?

  /*
  // TODO: Use this stuff if the example above is not a good start
  int PIDSuccess = updatePID();
  if !PIDSucess {
    //TODO: throw an alarm?
  }
  */

  //====== Send Data to the Pi ======
  // including the I-am-alive data
  // TODO: encapsulate the stuff in this if-statement
  if (pressureDataCount == NUM_OF_PRES_MEASUREMENTS) && (flowDataCount == NUM_OF_FLOW_MEASUREMENTS){

    // take average pressure
    double avgPressure = arrayAverage(pressureArray); 
    avgPressureArray[avgPressureCount] = avgPressure;
    avgPressureCount = (avgPressureCount + 1) % NUM_OF_PRES_MEASUREMENTS; // trying to intelligently ensure this doesnt become a massive number

    // take average flow
    double avgFlow = arrayAverage(flowArray);
    avgFlowArray[avgPressureCount] = avgFlow;
    avgFlowCount = (avgFlowCount + 1) % NUM_OF_FLOW_MEASUREMENTS; 

    sendData(avgPressure, avgFlow);

    // TODO: Check if data was recieved properly
    int sendTimeout = 0;
    while Serial.available(){ // TODO: I'm not totally sure of using this function - James
      piResp = Serial.readStringUntil('\n');

      if !piResp.equals('G'){ // bad response (TODO: we don't need the Arduino to know the Pi's state, right? Or )
        sendData(avgPressure, avgFlow); // send again
        sendTimeout++;
        if (sendTimeout == SEND_DATA_TIMEOUT){
          // TODO: Throw an alarm, is this the right alarm to call? do we need more functionality?
          keepAlarmRingingForever(); 
        }
      }
    }
    
    // Reset blocking flags
    blockingFlowReadings = 0;
    blockingPresReadings = 0;
    
  }
}// loop()


/*
  Sets the new parameters based on the parameters string.

  https://docs.google.com/document/d/17tNHzC1KAyru91LCRugWpDMOWfZAJPe1F5hpNLfNYW8/edit#
*/
void setNewParameters(String piString, struct parameters *newParams){
  if (!isChecksumValid(piString)) {
    // @TODO: Determine what to do if checksum wrong.
    return;
  }

  // Set parameters.
  newParams->mode = piString.charAt(1)
  newParams->fiO2 = piString.charAt(2)
  newParams->inspiratoryTime = piString.charAt(3)
  newParams->expiratoryTime = piString.charAt(4)
  newParams->peakInspiratoryPressure = piString.charAt(5)
  newParams->peakExpiratoryPressure = piString.charAt(6)
  newParams->sensitivity = piString.charAt(7)
  newParams->alarms.highPressureBound = piString.charAt(8)
  newParams->alarms.lowPressureBound = piString.charAt(9)
  newParams->alarms.highMinuteVentilationBound = piString.charAt(10)
  newParams->alarms.lowMinuteVentilationBound = piString.charAt(11)
  
  return;
}

int isIn

