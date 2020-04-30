#include "BatteryVoltageSensor.h"

BatteryVoltageSensor::BatteryVoltageSensor(int pin) {
  _pin = pin;
}

float BatteryVoltageSensor::read() {
  float batteryVoltage = (float) analogRead(_pin)*15.974/1024; // from eamon data sheeet
  return batteryVoltage;
}

int BatteryVoltageSensor::readPercentage() {
  // this isnt perfect (far from it as we dont know what the current draw is or the size of battery. this is a guess at best)
  float batteryVoltage = read();
  int batteryPercentage = constrain(map(batteryVoltage, 11.5, 13.7, 0, 100), 0, 100); 
  return batteryPercentage;
}