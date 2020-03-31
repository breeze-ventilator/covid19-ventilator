#include "OxygenPressureSensor.h"

void OxygenPressureSensor::OxygenPressureSensor(int pin) {
  _pin = pin;
}

unsigned int OxygenPressureSensor::read() {
  int mV = map(analogRead(_pin), 0, 1023, 0, 5000);
  int mPSI = mV * 0.1354 + 1010; //from amazon review so with grain of salt
  return floor(mPSI /1000); //return psi //floor((float)mPSI * 0.70307); // convert into mmH2O
}