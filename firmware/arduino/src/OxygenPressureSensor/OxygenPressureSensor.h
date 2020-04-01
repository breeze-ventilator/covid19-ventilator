#ifndef OXYGEN_PRESSURE_SENSOR_H
#define OXYGEN_PRESSURE_SENSOR_H

#include "Arduino.h"
class OxygenPressureSensor {
  public:
	  OxygenPressureSensor(int pin);
    unsigned int read();
  private:
    int _pin;
};

#endif