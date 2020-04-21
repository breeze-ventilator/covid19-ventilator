#include "BlowerFanServo.h"

BlowerFanServo::BlowerFanServo(int pin) {
  _pin = pin;
}

void BlowerFanServo::begin() {
  // Initialize the esc by giving 50% power wait for it to power up then 0% power and wait for beep then do an inaugural vroom for half a second
  // https://www.arduino.cc/en/Reference/ServoWrite
  // TODO: should we wait here?
  _blowerFan.attach(_pin);
  _blowerFan.write(90);
  delay(3000);
  _blowerFan.write(15);
  delay(3000);
}

void BlowerFanServo::turnOff() {
  _blowerFan.write(15);
}

void BlowerFanServo::writeBlowerPower(double blowerPower) {
  int bPower = (int) blowerPower;
  Serial.println(bPower);
  _blowerFan.write(bPower);
}