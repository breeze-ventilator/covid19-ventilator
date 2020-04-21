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
  blowerControl.begin();
  // oxygenControl.begin();
  batteryChargingControl.init();
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
  float setPressure = (float) state.desiredPressure; // TODO: Check units with below
  float actualPressure = data.getMainPressureAverageForPID();
  blowerControl.control(setPressure, actualPressure);
  // blowerControl.blowFan(100);
  // blowerControl.beQuiet();
}

void Controller::exhalationControl(Data &data, Parameters &parameters) {
  // TODO: uncomment below
  float setPressure = (float) parameters.currentPEEP;
  float actualPressure = data.getMainPressureAverageForPID();
  // Serial.println(actualPressure);
  // float setPressure = 0;
  // blowerControl.blowFan(50);
  blowerControl.control(setPressure, actualPressure);
  // blowerControl.beQuiet();
}

void Controller::blowFan(int blowerPower) {
  blowerControl.blowFan(blowerPower);
}

void Controller::manageBattery() {
  batteryChargingControl.control(1); // 1 amp
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