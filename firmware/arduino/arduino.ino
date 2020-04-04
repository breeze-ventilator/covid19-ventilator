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

// #include "src/initialization/initialization.h"
// #include "src/Data/Data.h"
// #include "src/Sensors/Sensors.h"
// #include "src/State/State.h"
#include "src/Controller/Controller.h"
// #include "src/PiCommunication/PiCommunication.h"

// 8 kBytes of sRAM, 4 kBytes of eepROM, 256 kBytes of code storage
// (eepRom: for bootup, a read-only memory whose contents can be erased and reprogrammed using a pulsed voltage.)

// read at 500 Hz, send to screen at 10 Hz (info from 50 datapoints each time)

/* pid updated every n (n=5?) datapoints:
  - proportional: average over last n (configurable) datapoints
  - derivative: linear fit over n values, where each value is an average of n datapoints (needs last n**2 datapoints)
*/

// Data data;
// Sensors sensors(FLOW_READING_FREQUENCY,
//                  MAIN_PRESSURE_READING_FREQUENCY,
//                  OXYGEN_PRESSURE_READING_FREQUENCY,
//                  BATTERY_VOLTAGE_READING_FREQUENCY);
Controller controller;
// PiCommunication piCommunications(BAUD_RATE, TIME_BETWEEN_PI_SENDING);
// State state;
// Parameters parameters;
/*
  On startup, initializes pins and ensures Pi sends message.

  On failure, hangs forever.
*/
void setup() {  
  Serial.begin(9600);
  controller.stopArduinoAlarm();
  // sensors.init();
  int servosConnectedErrorCode = controller.init();
  // parameters.currentMode = PRESSURE_CONTROL_MODE;
	// parameters.currentFiO2 = 70;
	// parameters.currentInspiratoryTime = 1000;
	// parameters.currentExpiratoryTime = 3000;
	// parameters.currentPeakInspiratoryPressure = 10000; // TODO: match pressure readings
	// parameters.currentPEEP = 5000;
	// parameters.currentSensitivity = 0;

  // int piCommunicationErrorCode = piCommunications.initCommunication(MAX_SERIAL_CONNECTION_WAIT_TIME, PI_MAX_WAIT_TIME, PI_PING_INTERVAL);
  // if (piCommunicationErrorCode != NO_ERROR) { // could also check for PI_SENT_WRONG_CODE_ERROR
  //   controller.ringAlarmForever();
  // }

  // if (servosConnectedErrorCode != NO_ERROR) {
  //   piCommunication.sendServosNotConnectedErrorToPi(servosConnectedErrorCode);
  // }
}

void loop() {
  // Check for Params 
  // if (piCommunications.isDataAvailable()) {
  //   String receivedString = piCommunications.getData();
  //   parameters.getNewParameters(receivedString);
  // }

  // sensors.readSensorsIfAvailableAndSaveSensorData(data);

  // state.updateState(parameters);

  // only update parameters when breath is over
  // if (parameters.newParamsHaveArrived && state.isStartingNewBreath) {
  //   parameters.updateCurrentParameters();
  // }

  // breathing cycle
  // if (state.breathingStage == INHALATION_STAGE) {
  Serial.println("loop");
  controller.inhalationControl();
  // }
  // else if (state.breathingStage == EXHALATION_STAGE) {
  //   controller.exhalationControl(data, parameters, state);
  // }

  // if (piCommunications.isTimeToSendDataToPi()) { // need to make sure pressure and flow are BOTH full
  //   piCommunications.sendDataToPi(data, state);
  //   data.resetPiDataExceptFlow();
    
  //   if (state.isStartingNewBreath) {
  //     data.resetPiFlowData();
  //   }
  // }
}
