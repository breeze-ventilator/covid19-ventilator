#include "BatteryVoltageSensor.h"

BatteryVoltageSensor::BatteryVoltageSensor(int pin) {
  _pin = pin;
}

int BatteryVoltageSensor::read() {
  int mV = map(analogRead(_pin), 0, 1023, 0, 5000);
  int batteryVoltage = floor((float)mV / 0.286); //voltage divider network
  return batteryVoltage;
}