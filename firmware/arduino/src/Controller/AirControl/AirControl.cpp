#include "AirControl.h"
#include "Arduino.h"

AirControl::AirControl(int pin, int offPin) {
  _pin = pin;
  _offPin = offPin;
  _fiO2 = 0;
}

void AirControl::begin() {
  airIntakeServo.attach(_pin);
  airIntakeServo.write(AIR_INTAKE_ZERO_POINT);
  pinMode(_offPin, OUTPUT);
}

void AirControl::control(int desiredFiO2) {
  if (desiredFiO2 != _fiO2) {
    _fiO2 = desiredFiO2;
    setOpening(100-desiredFiO2);
  }
}

void AirControl::setOpening(int percent){ // percent open we want
  activate();
  airIntakeServo.write(map(percent,0,100,110,180)); // 110 is closed and 180 is open 
  deactivate();
}

void AirControl::activate() {
  digitalWrite(_offPin, LOW);
}

void AirControl::deactivate() {
  digitalWrite(_offPin, HIGH);
}