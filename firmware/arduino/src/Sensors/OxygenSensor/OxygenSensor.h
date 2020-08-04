#ifndef OXYGEN_SENSOR_H
#define OXYGEN_SENSOR_H

#include "Arduino.h"
class OxygenSensor {
  public:
	  OxygenSensor(int pin);
    float read();
  private:
    int _pin;
    float floatMap(float x, float in_min, float in_max, float out_min, float out_max);
};

#endif