#include "MainPressureSensor.h"
/*
  Get a pressure reading.
*/

MainPressureSensor::MainPressureSensor() {

}

unsigned int MainPressureSensor::read() {
  // mm H2O
  float mV = map(analogRead(PRESSURE_PIN), 0, 1023, 0, 5000);
  float mA = mV / PRESSURE_SENSE_RESISTOR;
  return floor((mA - 4) * 25.4); // numbers set by datasheet
}

