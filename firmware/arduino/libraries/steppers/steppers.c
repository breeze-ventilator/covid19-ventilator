#include <Stepper.h>

#define STEPS_PER_REVOLUTION  100 // this is dependent on the motor and should be updated, will move to init.h 

Stepper O2Valve(STEPS_PER_REVOLUTION, O2_CONT_PIN0, O2_CONT_PIN1, O2_CONT_PIN2, O2_CONT_PIN3);

/*
  Initializes Stepper for O2 Valve.
*/
int initializeStepperMotor(int initializationTimeOut) {
  // https://www.instructables.com/id/Control-DC-and-stepper-motors-with-L298N-Dual-Moto/
  // Recommends example code from Stepper library: stepper_oneRevolution.ino

  O2Valve.setSpeed(O2_STEPPER_SPEED); // TODO: Does the stepper speed change?

  // Zero motor to know where the zero point is
  // (if the pin goes high, we are zero'd)
  int errCount = 0;  // how many?

  // TODO: Check if this is the right way to zero a stepper
  zeroSense = digitalRead(STEP_MOTOR_ZERO_PIN); // to see if already at 0
  while (zeroSense) {
    myStepper.step(-1); // -1 for counterclockwise, 1 for clockwise, TODO: Ask Simon which
    zeroSense = digitalRead(STEP_MOTOR_ZERO_PIN);
    delay(1); // lets the motor settle, may be unncessary (1ms?)
    count++;

    if (count == initializationTimeOut) {
      return 0;
    }
  }

  return 1; // we need error checking?
}