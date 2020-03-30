
#include "servos.h"
#include <Servo.h>

Servo blowerFan, airIntake;

int initializeBlowerFan() {
  blowerFan.attach(BLOWER_PIN);
  blowerFan.write(BLOW_FAN_INITIAL_POSITION); //// https://www.arduino.cc/en/Reference/ServoWrite

  return 1
}

int initializeAirIntake() {
  // See Arduino example file in IDE: Examples > Servo > Knob
  airIntake.attach(AIR_CONTROL_PIN);
  airIntake.write(AIR_INTAKE_INITIAL_POSITION);

  // TODO: Need to set the default position. Do these needs to be zero'd?

  return 1;
}

int initializeServos() {
  initializeAirIntake();
  initializeBlowerFan();
  return 1;
}