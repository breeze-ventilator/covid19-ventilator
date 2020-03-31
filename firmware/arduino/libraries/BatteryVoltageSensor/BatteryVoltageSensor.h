/*
  SFM3000wedo.cpp - Library for reading values from flowmeter Sensirion SFM3000wedo
  https://www.sensirion.com/en/flow-sensors/mass-flow-meters-for-high-precise-measurement-of-gases/low-pressure-drop-mass-flow-meter/
  Created by WeDo, Zuerich 20170616
  
  Released into the public domain.
  
  
  Pay attention to Scaling!!
  int offset = 32000; // Offset for the sensor
  float scale = 140.0; // Scale factor for Air and N2 is 140.0, O2 is 142.8
  Flow = (readvalue - offset) / scale
  
*/

#ifndef BATTERY_VOLTAGE_SENSOR_H
#define BATTERY_VOLTAGE_SENSOR_H
#include "Arduino.h"
class BatteryVoltageSensor {
  public:
	  BatteryVoltageSensor(int pin);
    int read();
    int readPercentage();
};
 
#endif
