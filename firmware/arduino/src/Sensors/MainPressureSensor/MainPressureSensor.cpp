#include "MainPressureSensor.h"
/*
  Get a pressure reading.
*/

MainPressureSensor::MainPressureSensor() {

}

unsigned int MainPressureSensor::read() {
  // mm H2O
  // float mV = map(analogRead(PRESSURE_PIN), 0, 1023, 0, 5000);
  // float mA = mV / PRESSURE_SENSE_RESISTOR;

  //above is sold sensor stuff

  int pressure = (5* ((analogRead(PRESSURE_PIN)/1024) -0.1)/0.8) *703;
  return pressure;
}

