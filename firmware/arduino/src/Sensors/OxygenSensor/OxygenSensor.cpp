#include "OxygenSensor.h"

OxygenSensor::OxygenSensor(int pin) {
  _pin = pin;
}

unsigned int OxygenSensor::read() {
  int oxygenConcentration = analogRead(_pin)*100/1024; 
  //this is not the real trasnfer function but i dont have it 

  return oxygenConcentration;
}