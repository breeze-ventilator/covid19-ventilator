#include "BlowerFanServo.h"

BlowerFanServo::BlowerFanServo(int pin) {
  _pin = pin;
}

void BlowerFanServo::begin() {
  // Initialize the esc by giving 50% power wait for it to power up then 0% power and wait for beep then do an inaugural vroom for half a second
  // https://www.arduino.cc/en/Reference/ServoWrite
  delay(5000);
  _blowerFan.attach(_pin, 1000, 2000);
  _blowerFan.write(0);
  delay(3000);
}

void BlowerFanServo::turnOff() {
  _blowerFan.write(0);
}

void BlowerFanServo::writeBlowerPower(double blowerPower) {
  int bPower = (int) blowerPower;
  _blowerFan.write(bPower);
}