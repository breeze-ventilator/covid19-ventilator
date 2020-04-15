#include "BatteryVoltageSensor.h"

BatteryVoltageSensor::BatteryVoltageSensor(int pin) {
  _pin = pin;
}

float BatteryVoltageSensor::read() {
  // Serial.println(analogRead(_pin));
  float V = (float) analogRead(_pin)*15.974/1024; // from eamon data sheeet
  return V;
}

int BatteryVoltageSensor::readPercentage() {
  float batteryVoltage = read();
  int batteryPercentage = constrain(map(batteryVoltage, 11.3, 12.8, 0, 100), 0, 100); 
  //this isnt perfect (far from it as we dont know what the current draw is or the size of battery. this is a guess at best)
  return batteryPercentage;
}