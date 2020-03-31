#include "BatteryVoltageSensor.h"

BatteryVoltageSensor::BatteryVoltageSensor(int pin) {
  _pin = pin;
}

int BatteryVoltageSensor::read() {
  int mV = map(analogRead(_pin), 0, 1023, 0, 5000);
  int batteryVoltage = floor((float)mV / 0.286); //voltage divider network
  return batteryVoltage;
}

int BatteryVoltageSensor::readPercentage() {
  int batteryVoltage = read();
  int batteryPercentage = constrain(map(batteryVoltage, 11000, 12800, 0, 100), 0, 100);
  return batteryPercentage;
}