#include "OxygenSensor.h"

OxygenSensor::OxygenSensor(int pin) {
  _pin = pin;
}

float OxygenSensor::read() {
  float voltage = map(analogRead(_pin),0, 1024, 0, 5);
  float oxygenConcentration =  map((voltage/40), 0.025, 0.115, 21, 100);
  //this is final trsanfer function

  return oxygenConcentration;
}