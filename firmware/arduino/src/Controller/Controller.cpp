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
  // Serial.println("Controller init");
  // blowerControl.begin();
  oxygenControl.begin();
  // airIntakeServo.begin();
  return 0;
}

void Controller::stopArduinoAlarm() {
  alarm.stopAlarm();
}

// void Controller::ringAlarmForever() {
//   alarm.keepAlarmRunningForever();
// }

void Controller::inhalationControl(Data &data) {
  // modify steps on stepper motor to get desired flow rate (which then gives concentration)
  // if (isTimeToControlOxygen()) {
  oxygenControl.control(100);
  // oxygenControl.control(random(100));
  // oxygenControl(data, parameters, state);
    // _lastOxygenControlTime = millis();
  // }
  // if (isTimeToControlAir()) {
  //  airControl(parameters);
  //  _lastAirControlTime = millis();
  // }
  float setPressure = 40;//(float) parameters.currentPeakInspiratoryPressure; //TODO: Check units with below
  float actualPressure = data.getMainPressureAverageForPID();
  // blowerControl.control(setPressure, actualPressure);
}

// void Controller::exhalationControl(Data data, Parameters parameters, State state) {
//   // if (isTimeToControlOxygen()) {
//   //   oxygenControl(data, parameters, state);
//   //   _lastOxygenControlTime = millis();
//   // }
//   // if (isTimeToControlAir()) {
//   //  airControl(parameters);
//   //  _lastAirControlTime = millis();
//   // }
//   float setPressure = (float) parameters.currentPEEP; //TODO: Check units with below. Also, should be an int or float?
//   float actualPressure = data.getMainPressureAverageForPID();
//   blowerControl.control(setPressure, actualPressure);
//   // modify steps on stepper motor to get desired flow rate (which then gives concentration)
// }

// void Controller::airControl(Parameters parameters) {
//   airIntakeServo.setOpening(100 - parameters.currentFiO2);
// }

// int Controller::isTimeToControlOxygen() {
//   return isTimeToRead(_lastOxygenControlTime, TIME_BETWEEN_OXYGEN_CONTROLS);
// }

// int Controller::isTimeToControlAir() {
//   return isTimeToRead(_lastAirControlTime, TIME_BETWEEN_AIR_CONTROLS);
// }

// int Controller::isTimeToRead(unsigned long lastReadTime, int timeBetweenReadings) {
//   unsigned long currentTime = millis();
//   unsigned long timeDifference = currentTime - lastReadTime;
//   if (timeDifference >= timeBetweenReadings) {
//     return 1;
//   }
//   else {
//     return 0;
//   }
// }