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
#include "initializations.h"
#include "Data.h"
#include "Sensors.h"
#include "Controller.h"
#include "State.h"

// 8 kBytes of sRAM, 4 kBytes of eepROM, 256 kBytes of code storage
// (eepRom: for bootup, a read-only memory whose contents can be erased and reprogrammed using a pulsed voltage.)

// read at 500 Hz, send to screen at 10 Hz (info from 50 datapoints each time)

/* pid updated every n (n=5?) datapoints:
  - proportional: average over last n (configurable) datapoints
  - derivative: linear fit over n values, where each value is an average of n datapoints (needs last n**2 datapoints)
*/

Data data();
Sensors sensors();
Controller controller();
PiCommunication piCommunications();
State state();
Parameters parameters();
/*
  On startup, initializes pins and ensures Pi sends message.

  On failure, hangs forever.
*/
void setup() {
  controller.stopArduinoAlarm();
  sensors.init();
  int servosConnectedErrorCode = controller.init();
  int piCommunicationErrorCode = piCommunications.initCommunication(MAX_SERIAL_CONNECTION_WAIT_TIME, PI_MAX_WAIT_TIME, PI_PING_INTERVAL);
  if (piCommunicationErrorCode != NO_ERROR) { // could also check for PI_SENT_WRONG_CODE_ERROR
    controller.ringAlarmForever();
  }

  // if (servosConnectedErrorCode != NO_ERROR) {
  //   piCommunication.sendServosNotConnectedErrorToPi(servosConnectedErrorCode);
  // }
}

void loop() {
  // Check for Params 
  if (piCommunication.isDataAvailable()) {
    String receivedString = piCommunication.getData();
    parameters.getNewParameters(receivedString);
  }

  sensors.readSensorsIfAvailableAndSaveSensorData(&data);

  state.updateState(&Parameters);

  // only update parameters when breath is over
  if (newParamsHaveArrived() && state.isStartingNewBreath) {
    parameters.updateCurrentParameters();
  }

  // breathing cycle
  if (state.breathingStage == INHALATION) {
    control.inhalationControl(&data, &parameters, &state);
  }
  else if (state.breathingStage == EXHALATION) {
    control.exhalationControl(&data, &parameters, &state);
  }

  if (isTimeToSendDataToPi(&data)) { // need to make sure pressure and flow are BOTH full
    piCommunications.sendDataToPi(&data, &state);
    data.resetPiDataExceptFlow();
    
    if (state.isStartingNewBreath) {
      data.resetPiFlowData();
    }
  }
}