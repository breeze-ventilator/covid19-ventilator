#ifndef OXYGEN_PRESSURE_SENSOR_H
#define OXYGEN_PRESSURE_SENSOR_H

class OxygenPressureSensor {
  public:
	  OxygenPressureSensor();
    unsigned int read();
  private:
    int _pin;
};

#endif