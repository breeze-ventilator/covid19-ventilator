
#include "servos.h"
#include <Servo.h>

Servo blowerFan, airIntake;

void initializeBlowerFan() {
  blowerFan.attach(BLOWER_PIN);
  // Initialzie the esc by giving 100% power wait for beep then 0% power and wait for beep
  blowerFan.write(0); // https://www.arduino.cc/en/Reference/ServoWrite
  delay(100);
  blowerFan.write(180);
  delay(2000);
  blowerFan.write(0);
  delay(2000);
}

void initializeAirIntake() {
  // See Arduino example file in IDE: Examples > Servo > Knob
  airIntake.attach(AIR_CONTROL_PIN);
  delay(10);
  airIntake.write(AIR_INTAKE_ZERO_POINT);
}

void initializeServos() {
  initializeAirIntake();
  initializeBlowerFan();
}