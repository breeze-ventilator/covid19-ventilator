#include "AirIntakeServo.h"
#include <Servo.h>

AirIntakeServo::AirIntakeServo(int pin, int zeroPoint) {
  airIntake.attach(pin);
  airIntake.write(zeroPoint)
}

