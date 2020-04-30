#include "Arduino.h"

#include "Controller.h"

Controller::Controller()
    : oxygenControl(),
    // alarm(ALARM_PIN),
    airControl(AIR_INTAKE_PIN, AIR_INTAKE_OFF_PIN),
    blowerControl(),
    batteryChargingControl(BATTERY_SENSE_PIN, BATTERY_CONTROL_PIN)
{
  
}

void Controller::init() {
  oxygenControl.begin();
  batteryChargingControl.init();
  blowerControl.begin();
  airControl.begin();
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
  //  airControl(parameters);
  controlPressure(state.desiredPressure, data);
  airControl.control(parameters.currentFiO2);
  oxygenControl.control(parameters.currentFiO2, data);
}

void Controller::exhalationControl(Data &data, Parameters &parameters) {
  controlPressure(parameters.currentPEEP, data);
  airControl.control(parameters.currentFiO2);
  oxygenControl.control(parameters.currentFiO2, data);
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

void Controller::standby() {
  blowerControl.beQuiet();
  oxygenControl.zero();
}

void Controller::manageBattery() {
  batteryChargingControl.control(1); // 1 amp
}

void Controller::delayWithCharging(unsigned long delayTime) {  
  while (delayTime >= 10) {
    delay(10);
    manageBattery();
    delayTime -= 10;
  }
  delay(delayTime);
}