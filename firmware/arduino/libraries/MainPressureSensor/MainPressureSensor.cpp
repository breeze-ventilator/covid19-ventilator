#include "MainPressureSensor.h"
/*
  Get a pressure reading.
*/

void MainPressureSensor::MainPressureSensor()

void MainPressureSensor::read() {
  int mV = map(analogRead(PRESSURE_PIN), 0, 1023, 0, 5000);
  float mA = mV / PRESSURE_SENSE_RESISTOR;
  return floor((mA -4) * 25.4); // numbers set by datasheet
}

