#include "AirIntakeServo.h"
#include <Servo.h>

AirIntakeServo::AirIntakeServo(int pin, int zeroPoint) {
  _airIntake.attach(pin);
  _airIntake.write(zeroPoint);
}

void AirIntakeServo::setOpening(int percent){ //percent open we want
  _airIntake.write(map(percent,0,100,110,180)); //110 is closed and 180 is open 
}

