#include "MainPressureSensor.h"
/*
  Get a pressure reading.
*/

MainPressureSensor::MainPressureSensor() {

}

float MainPressureSensor::read() {
  // mm H2O
  float pressure = (5.0* ((analogRead(PRESSURE_PIN)/1024.0) - 0.1) / 0.8) * 703;
  return pressure;
}

