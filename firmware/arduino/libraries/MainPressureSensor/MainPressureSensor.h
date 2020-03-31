#ifndef MAIN_PRESSURE_SENSOR_H
#define MAIN_PRESSURE_SENSOR_H

#define PRESSURE_PIN 6
#define PRESSURE_SENSE_RESISTOR 180

class MainPressureSensor {
  public:
    MainPressureSensor();
    unsigned int read();
};