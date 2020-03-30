#include "BlowerFanServo.h"
#include <Servo.h>

BlowerFanServo::BlowerFanServo(int pin) {
  blowerFan.attach(pin);
}

void BlowerFanServo::begin() {
  // Initialize the esc by giving 100% power wait for beep then 0% power and wait for beep
  // https://www.arduino.cc/en/Reference/ServoWrite
  // TODO: should we wait here?
  blowerFan.write(0);
  delay(100);
  blowerFan.write(180);
  delay(2000);
  blowerFan.write(0);
  delay(2000);
}