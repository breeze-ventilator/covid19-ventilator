// 8 kBytes of sRAM, 4 kBytes of eepROM, 256 kBytes of code storage
// (eepRom: for bootup, a read-only memory whose contents can be erased and reprogrammed using a pulsed voltage.)

#include "src/Parameters/Parameters.h"
#include "src/Data/Data.h"
#include "src/Sensors/Sensors.h"
#include "src/State/State.h"
#include "src/Controller/Controller.h"
#include "src/PiCommunication/PiCommunication.h"
#include "src/Defs/errors.h"

Data data;
Sensors sensors(FLOW_READING_FREQUENCY,
                 MAIN_PRESSURE_READING_FREQUENCY,
                 OXYGEN_READING_FREQUENCY,
                 BATTERY_VOLTAGE_READING_FREQUENCY);
Controller controller;
PiCommunication piCommunication(BAUD_RATE, TIME_BETWEEN_DATA_SENDING_TO_PI);
State state;
Parameters parameters;

void setup() {
  Serial.begin(9600);
  
  // controller.stopArduinoAlarm();
  controller.init();
  sensors.init();
  int piCommunicationErrorCode = piCommunication.initCommunication(PI_PING_INTERVAL, controller);
  // if (piCommunicationErrorCode != NO_ERROR) { // could also check for PI_SENT_WRONG_RESPONSE_ERROR
  //   controller.ringAlarmForever();
  // }

  // if (servosConnectedErrorCode != NO_ERROR) {
  //   piCommunication.sendServosNotConnectedErrorToPi(servosConnectedErrorCode);
  // }
  // parameters.currentMode = PRESSURE_CONTROL_MODE;
  // parameters.currentFiO2 = 80;
  // parameters.currentInspiratoryTime = 4000;
  // parameters.currentMaxExpiratoryTime = 3000;
  // parameters.currentInspiratoryPressure = 250; // mm H2O
  // parameters.currentPEEP = 50; // mm H2O
  // parameters.currentRiseTime = 100; // ms
  // parameters.currentSensitivity = -1; // L
  // parameters.currentApneaTime = 6000; // ms
  // parameters.currentFlowCyclingOffPercentage = 0.20; // 20%
}

void loop() {
  // Check for Params
  if (piCommunication.isDataAvailable()) {
    char messageType = piCommunication.getMessageType();
    if (messageType == 'P')
    {
      piCommunication.getParametersFromPi();
      parameters.getNewParameters(piCommunication.parametersBuffer);
    }
    else if (messageType == 'G')
    {
      // Pi is awake, should alarm if it hasn't been awake for a while
      piCommunication.flush();
    }
  }

  state.updateState(parameters, data);

  sensors.readSensorsIfAvailableAndSaveSensorData(data, state);

  // only update parameters when breath is over
  if (parameters.newParamsHaveArrived && state.breathCompleted) {
    parameters.updateCurrentParameters();
    controller.controlAir(parameters);
    if (parameters.currentMode == OFF_MODE) {
      controller.standby();
    }
  }

  // breathing cycle
  controller.manageBattery();
  // controller.blowFan(90);
  if (state.breathingStage == INHALATION_STAGE && parameters.currentMode != OFF_MODE) {
    controller.inhalationControl(data, parameters, state);
  }
  else if (state.breathingStage == EXHALATION_STAGE && parameters.currentMode != OFF_MODE) {
    controller.exhalationControl(data, parameters);
  }

  if (state.breathCompleted && state.mode != OFF_MODE) {
    piCommunication.updateValuesForPiUponBreathCompleted(data, state); // if breath = 1, set value to send to 1.
    data.resetTidalVolume();
  }

  piCommunication.updateErrors(state, data);

  // reset state errors
  if (state.apneaTimeExceededError != NO_ERROR) {
    state.apneaTimeExceededError = NO_ERROR;
  }
  
  if (piCommunication.isTimeToSendDataToPi()) {
    piCommunication.sendDataToPi(data, state);
  }
}
