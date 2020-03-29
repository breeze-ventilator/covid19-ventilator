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
String mode = 'SETUP';

// Data storage arrays
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
  String mode;
  int fiO2;
  int inspiratoryTime;
  int exspiratoryTime;
  int peakInspiratoryPressure;
  int peakExpiratoryPressure;
  
  struct alarms {
    int highPressureBound;
    int lowPressureBound;

    int highMinuteVentilationBound;
    int lowMinuteVentilationBound;
  }
};


/*
  On startup, initializes pins and ensures Pi sends message.

  On failure, hangs forever.
*/
void setup() {
  initializePins();
  bool piConnected = initializePiCommunication(PI_MAX_WAIT_TIME); 
  bool servosConnected = initializeServos();
  bool stepperConnected = initializeStepperMotor(); // needs a timeout

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
void loop() {

  // ===== Check for Params ====

  if Serial.available(){
    String recievedString = Serial.readStringUntil("\n"); // reads up-to-but-not-including '\n' char
    parsePiString(recievedString);
  }



  if (mode.equals('SETUP')) {
    // Continously waits for the setup parameters from pi.
    struct parameters params = initializeParametersFromPi();
    mode = params.mode;
  }

  // Error checking variables
  // @ALL: Were we going to do an error checking function at the end or make each function self-checking?
  int reading_success = 0;

  //we will re-set system time every breath cycle is complete and when this happens we will let the pi know so that it can check breaths per minute
  //struct measurements readings = getAllReadings();
 
  // ===== getAllReadings v2 ====
  currentTime = millis();
  if( ((currentTime - lastPresReadTime) >= PRES_READ_RATE) && (!blockingPresReadings)  ) {
    getFlowReading();
  }
  currentTime = millis();
  if( ((currentTime - lastFlowReadTime) >= FLOW_READ_RATE)&& (!blockingFlowReadings)  ){
    getPressureReading();
  }

  // ===== Breathing cycle ====
  if inhale{
    inhalation();
  }
  if exhale{
    exhalation();
  }


  if(patientTriggered){//if in patient triggered mode look for breath attempt
    resetSystemTime();
  }
  //  setPressure(inhalePressure);


  sendAlarm(alarmMessage); //send the alarm to the pi    @ALL: why is this placed here?
  while (systemTime < howLongIWantToWait){
    waitForConfirmation();
  }

  // send info to the pi including the I am alive data, and reset data storage stuff
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

  }
}

/*
  Runs a breath cycle.
*/
void runBreathCycle(){

  return;
}
