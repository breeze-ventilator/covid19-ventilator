#include "Arduino.h"

#include "Controller.h"

Controller::Controller()
    : oxygenControl(),
    alarm(ALARM_PIN),
    // airIntakeServo(AIR_INTAKE_PIN, AIR_INTAKE_ZERO_POINT),
    blowerControl()
{
  _lastOxygenControlTime = 0;
  _lastAirControlTime = 0;
}

int Controller::init() {
  blowerControl.begin();
  oxygenControl.begin();
  // airIntakeServo.begin();
  return 0;
}

void Controller::stopArduinoAlarm() {
  alarm.stopAlarm();
}

void Controller::startArduinoAlarm() {
  // runs forever and blocks everything after it
  alarm.startAlarm();
}

void Controller::inhalationControl(Data &data, Parameters &parameters) {
  // oxygenControl.control(100);
  // oxygenControl.control(random(100));
  // oxygenControl(data, parameters, state);

  //  airControl(parameters);
  float setPressure = (float) parameters.currentPEEP + parameters.currentInspiratoryPressure; //TODO: Check units with below
  float actualPressure = data.getMainPressureAverageForPID();
  // blowerControl.control(setPressure, actualPressure);
  blowerControl.beQuiet();
}

void Controller::exhalationControl(Data &data, Parameters &parameters) {
  float setPressure = (float) parameters.currentPEEP;
  float actualPressure = data.getMainPressureAverageForPID();
  blowerControl.beQuiet();
  // blowerControl.control(setPressure, actualPressure);
}

// void Controller::airControl(Parameters parameters) {
//   airIntakeServo.setOpening(100 - parameters.currentFiO2);
// }

// int Controller::isTimeToControlOxygen() {
//   return isTime(_lastOxygenControlTime, TIME_BETWEEN_OXYGEN_CONTROLS);
// }

// int Controller::isTimeToControlAir() {
//   return isTime(_lastAirControlTime, TIME_BETWEEN_AIR_CONTROLS);
// }