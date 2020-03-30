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

#include "init.h"
#include "Data.h"
#include "Sensors.h"
#include "Controller.h"

// 8 kBytes of sRAM, 4 kBytes of eepROM, 256 kBytes of code storage
// (eepRom: for bootup, a read-only memory whose contents can be erased and reprogrammed using a pulsed voltage.)

// read at 500 Hz, send to screen at 10 Hz (info from 50 datapoints each time)

/* pid updated every n (n=5?) datapoints:
  - proportional: average over last n (configurable) datapoints
  - derivative: linear fit over n values, where each value is an average of n datapoints (needs last n**2 datapoints)
*/

struct State {
  bool isStartingNewBreath;
  unsigned long startTime;
  unsigned int breathingStage; // inhilation or exhilation
} state;

struct Parameters {
  unsigned int mode;
  unsigned int fiO2;
  unsigned int inspiratoryTime;
  unsigned int expiratoryTime;
  unsigned int peakInspiratoryPressure;
  unsigned int peakExpiratoryPressure;
  unsigned int sensitivity;
  
  struct Alarms {
    unsigned int highPressureBound;
    unsigned int lowPressureBound;

    unsigned int highMinuteVentilationBound;
    unsigned int lowMinuteVentilationBound;
  } alarms;
};

struct Parameters currentParams;
struct Parameters newParams;

Data data;
Sensors sensors;
Controller controller;
/*
  On startup, initializes pins and ensures Pi sends message.

  On failure, hangs forever.
*/
void setup() {
  stopArduinoAlarm();
  
  initializeFlow();
  initializeServos();
  bool stepperConnected = initializeStepperMotor(STEPPER_MAX_INITIALIZATION_TIME);
  bool piConnected = initializePiCommunication(PI_MAX_WAIT_TIME); 
  if (!piConnected) {
    turnOnAlarm();
  }

  if (!servosConnected || !stepperConnected) {
    sendErrorToPi();
  }
  initializeState(&state);
  currentParams.mode = WAITING_FOR_PARAMETERS;
}

/*
  Main Loop
*/
void loop() {
  // Check for Params 
  if (Serial.available()) {
    String receivedString = Serial.readStringUntil("\n"); // reads up-to-but-not-including '\n' char
    setNewParameters(receivedString, &newParams);
  }

  readSensorsIfAvailableAndSaveSensorData(&data);

  updateState(&state, currentParams);

  // only update parameters when breath is over
  if (newParamsHaveArrived() && state.isStartingNewBreath) {
    updateCurrentParameters(&currentParams, &newParams);
  }

  if (curentParams.mode == PRESSURE_SUPPORT_MODE && state.isStartingNewBreath) {
    // we will re-set system time every breath cycle is complete and when
    // this happens we will let the pi know so that it can check breaths per minut
    tellPiThatStartingNewBreath(&piMessageQueue);
  }

  // breathing cycle
  if (state.breathingStage == INHALATION) {
    inhalationControl(&data, currentParams);
  }
  else if (state.breathingStage == EXHALATION) {
    exhalationControl(&data, currentParams);
  }

  if (isTimeToSendDataToPi(&data)) { // need to make sure pressure and flow are BOTH full
    sendDataToPi(&data);
    clearData(&(data.forPI));
  }
}

void updateState(struct State *state, struct Parameters currentParams) {
  if (currentParams.mode == PRESSURE_CONTROL_MODE) {
    pressureControlUpdateState(&state); // checks time to see if time to switch from inhilation to exhilation
  }
  else if (currentParams.mode == PRESSURE_SUPPORT_MODE) {
    pressureSupportUpdateState(&state, currentParams); // should use state.lastFlowValue, state.peakFlowValueInCurrentBreath
  }
}



// // Other stuff:

// //====== Send Data to the Pi ======
//   // including the I-am-alive data
//   // TODO: encapsulate the stuff in this if-statement
//   if (pressureDataCount == NUM_OF_PRES_MEASUREMENTS) && (flowDataCount == NUM_OF_FLOW_MEASUREMENTS){

//     // take average pressure
//     double avgPressure = arrayAverage(pressureArray); 
//     avgPressureArray[avgPressureCount] = avgPressure;
//     avgPressureCount = (avgPressureCount + 1) % NUM_OF_PRES_MEASUREMENTS; // trying to intelligently ensure this doesnt become a massive number

//     // take average flow
//     double avgFlow = arrayAverage(flowArray);
//     avgFlowArray[avgPressureCount] = avgFlow;
//     avgFlowCount = (avgFlowCount + 1) % NUM_OF_FLOW_MEASUREMENTS; 

//     sendData(avgPressure, avgFlow);

//     // TODO: Check if data was recieved properly
//     int sendTimeout = 0;
//     while Serial.available(){ // TODO: I'm not totally sure of using this function - James
//       piResp = Serial.readStringUntil('\n');

//       if !piResp.equals('G'){ // bad response (TODO: we don't need the Arduino to know the Pi's state, right? Or )
//         sendData(avgPressure, avgFlow); // send again
//         sendTimeout++;
//         if (sendTimeout == SEND_DATA_TIMEOUT){
//           // TODO: Throw an alarm, is this the right alarm to call? do we need more functionality?
//           keepAlarmRingingForever(); 
//         }
//       }
//     }
    
//   }

// // ===== Take readings ====
//   currentTime = millis();
//   if( ((currentTime - lastPresReadTime) >= PRES_READ_RATE)) {
//     getFlowReading();
//   }
//   currentTime = millis();
//   if( ((currentTime - lastFlowReadTime) >= FLOW_READ_RATE) ){
//     getPressureReading();
//   }


//   if (mode == patientTriggered){//if in patient triggered mode look for breath attempt?
//     resetSystemTime(); // @ALL: is system time a thing? Is it for making sure we get a minimum # of breaths per minute?
//   }
//   //  setPressure(inhalePressure);



//   sendAlarm(alarmMessage); //send the alarm to the pi    @ALL: why is this placed here?
//   while (systemTime < howLongIWantToWait){
//     waitForConfirmation();
//   }