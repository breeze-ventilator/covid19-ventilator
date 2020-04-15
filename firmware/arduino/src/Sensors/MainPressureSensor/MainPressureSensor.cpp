#include "MainPressureSensor.h"
/*
  Get a pressure reading.
*/

MainPressureSensor::MainPressureSensor(int pin) {
  _pin = pin;
}

float MainPressureSensor::read() {
  // mm H2O
  float pressure = (5.0* ((analogRead(_pin)/1024.0) - 0.1) / 0.8) * 703;
  return pressure;
}

