#include "AirIntakeServo.h"
#include "Arduino.h"

AirIntakeServo::AirIntakeServo(int pin, int zeroPoint, int offPin) {
  _pin = pin;
  _zeroPoint = zeroPoint;
  _offPin = offPin;
}

void AirIntakeServo::begin() {
  _airIntake.attach(_pin);
  _airIntake.write(_zeroPoint);
  pinMode(_offPin, OUTPUT);
}

void AirIntakeServo::setOpening(int percent){ //percent open we want
  _airIntake.write(map(percent,0,100,110,180)); //110 is closed and 180 is open 
}



void AirIntakeServo::setState(bool state){
  if (state){
    digitalWrite(_offPin, HIGH);
  } else {
    digitalWrite(_offPin, LOW);
  }
}