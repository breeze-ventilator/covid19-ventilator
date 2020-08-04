#include "OxygenSensor.h"

OxygenSensor::OxygenSensor(int pin) {
  _pin = pin;
}

float OxygenSensor::read() {
  float voltage = floatMap(analogRead(_pin),0, 1024, 0, 5);
  float oxygenConcentration = floatMap((voltage/40.0), 0.025, 0.115, 21, 100);
  return oxygenConcentration;
}

float OxygenSensor::floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}