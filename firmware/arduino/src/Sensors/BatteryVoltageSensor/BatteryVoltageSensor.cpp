#include "BatteryVoltageSensor.h"

BatteryVoltageSensor::BatteryVoltageSensor(int pin) {
  _pin = pin;
}

int BatteryVoltageSensor::read() {
  Serial.println(analogRead(_pin));
  float mV = (float) map(analogRead(_pin), 0, 1023, 0, 5000);
  int batteryVoltage = floor(mV / 0.286); //voltage divider network
  // Serial.println(batteryVoltage);
  return batteryVoltage;
}

int BatteryVoltageSensor::readPercentage() {
  int batteryVoltage = read();
  int batteryPercentage = constrain(map(batteryVoltage, 11000, 12800, 0, 100), 0, 100);
  return batteryPercentage;
}