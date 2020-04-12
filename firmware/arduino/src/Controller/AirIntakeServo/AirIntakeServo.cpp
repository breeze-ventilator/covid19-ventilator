#include "AirIntakeServo.h"
#include "Arduino.h"

AirIntakeServo::AirIntakeServo(int pin, int zeroPoint) {
  _pin = pin;
  _zeroPoint = zeroPoint;
}

void AirIntakeServo::begin() {
  _airIntake.attach(_pin);
  _airIntake.write(_zeroPoint);
}

void AirIntakeServo::setOpening(int percent){ //percent open we want
  _airIntake.write(map(percent,0,100,110,180)); //110 is closed and 180 is open 
}

