#include "AirControl.h"
#include "Arduino.h"

AirControl::AirControl(int pin) {
  _pin = pin;
}

void AirControl::begin() {
  airIntakeServo.attach(_pin);
  airIntakeServo.write(AIR_INTAKE_ZERO_POINT);
}

void AirControl::control(int desiredFiO2) {
  setOpening(100-desiredFiO2);
}

void AirControl::setOpening(int percent){ // percent open we want
  airIntakeServo.write(map(percent,0,100,110,180)); // 110 is closed and 180 is open 
}

