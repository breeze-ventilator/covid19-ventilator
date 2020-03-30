#include "AirIntakeServo.h"
#include <Servo.h>

AirIntakeServo::AirIntakeServo(int pin, int zeroPoint) {
  airIntake.attach(pin);
}

void AirIntakeServo::begin() {
  // Initialize the esc by giving 100% power wait for beep then 0% power and wait for beep
  // https://www.arduino.cc/en/Reference/ServoWrite
  delay(10);
  airIntake.write(zeroPoint);

  airIntake.write(0);
  delay(100);
  airIntake.write(180);
  delay(2000);
  airIntake.write(0);
  delay(2000);
}