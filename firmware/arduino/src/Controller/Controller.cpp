#include "Arduino.h"

#include "Controller.h"

Controller::Controller()
    : // oxygenControl(),
    // alarm(ALARM_PIN),
    // airIntakeServo(AIR_INTAKE_PIN, AIR_INTAKE_ZERO_POINT),
    blowerControl(),
    batteryChargingControl(BATTERY_SENSE_PIN, BATTERY_CONTROL_PIN)
{
  _lastAirControlTime = 0;
}

void Controller::init() {
  // oxygenControl.begin();
  batteryChargingControl.init();
  blowerControl.begin();
  // airIntakeServo.begin();
}

void Controller::stopArduinoAlarm() {
  // alarm.stopAlarm();
  return;
}

void Controller::startArduinoAlarm() {
  // runs forever and blocks everything after it
  // alarm.startAlarm();
  return;
}

void Controller::inhalationControl(Data &data, Parameters &parameters, State &state) {
  // oxygenControl.control(100);
  // oxygenControl.control(random(100));
  // oxygenControl(data, parameters, state);
  // oxygenControl.control();

  //  airControl(parameters);
  controlPressure(state.desiredPressure, data);
}

void Controller::exhalationControl(Data &data, Parameters &parameters) {
  controlPressure(parameters.currentPEEP, data);
}

void Controller::controlPressure(float desiredPressure, Data &data) {
  float actualPressure = data.getMainPressureAverageForPID();
  blowerControl.control(desiredPressure, actualPressure);
  // Serial.println(actualPressure);
  // float setPressure = 0;
  // blowerControl.blowFan(15);
  // blowerControl.beQuiet();
}

void Controller::blowFan(int blowerPower) {
  blowerControl.blowFan(blowerPower);
}

void Controller::manageBattery() {
  batteryChargingControl.control(5); // 1 amp
}

// void Controller::airControl(Parameters parameters) {
//   airIntakeServo.setOpening(100 - parameters.currentFiO2);
// }

// int Controller::isTimeToControlAir() {
//   return isTime(_lastAirControlTime, TIME_BETWEEN_AIR_CONTROLS);
// }

// int Controller::isTimeToControlBatteryCharging() {
//   return isTime(_lastbatteryControlTime, TIME_BETWEEN_BATTERY_CONTROLS);
// }