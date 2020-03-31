#include "BlowerFanServo.h"
#include <Servo.h>

BlowerFanServo::BlowerFanServo(int pin) {
  blowerFan.attach(pin);
}

void BlowerFanServo::begin() {
  // Initialize the esc by giving 100% power wait for beep then 0% power and wait for beep
  // https://www.arduino.cc/en/Reference/ServoWrite
  // TODO: should we wait here?
  blowerFan.write(90);
  delay(100);
  blowerFan.write(15);
  delay(4000);
  blowerFan.write(90);
  delay(1000);
  blowerFan.write(15);
}