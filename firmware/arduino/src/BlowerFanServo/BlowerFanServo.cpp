#include "BlowerFanServo.h"

BlowerFanServo::BlowerFanServo(int pin) {
  _blowerFan.attach(9);
  // Initialize the esc by giving 50% power wait for it to power up then 0% power and wait for beep then do an inaugural vroom for half a second
  // https://www.arduino.cc/en/Reference/ServoWrite
  // TODO: should we wait here?

}
void BlowerFanServo::begin() {
  _blowerFan.write(90);
  delay(4000);
  _blowerFan.write(15);
  delay(2000);
}

void BlowerFanServo::turnOff() {
  _blowerFan.write(15);
  _blowerFan.write(15);
}

void BlowerFanServo::write(int x) {
  _blowerFan.write(x);
}

void BlowerFanServo::writeBlowerPower(double blowerPower) {
  _blowerFan.write(map(blowerPower, 0, 256, 15, 90)); // 15 to 90 instead of 15 to 180
}