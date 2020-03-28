#include <Stepper.h>

//Servo blowerFan;
//Servo airIntake;

int stepsPerRevolution = 100; // this is dependent on the motor and should be updated
// these need to be global
Stepper blowerFan(stepsPerRevolution, 8, 9, 10, 11);
Stepper airIntake(stepsPerRevolution, 8, 9, 10, 11); 
Stepper O2Valve(stepsPerRevolution, O2_CONT_PIN0,O2_CONT_PIN1,O2_CONT_PIN2,O2_CONT_PIN3);

int initializePins() {
  // https://www.arduino.cc/en/Tutorial/DigitalPins

  // inputs
  pinMode(PRESSURE_PIN, input);
  pinMode(FLOW_PIN, input);
  pinMode(BATT_PIN, input);
  pinMode(FAN_SENS_PIN, input);
  
  // outputs
  blowerFan.attach(BLOWER_PIN);
  airIntake(AIR_CONT_PIN);
  pinMode(ALARM_PIN, output);
  pinMode(O2_CONT_PIN0, output); // Why is the macro name red...
  pinMode(O2_CONT_PIN1, output); // Why is the macro name red...
  pinMode(O2_CONT_PIN2, output); // Why is the macro name red...
  pinMode(O2_CONT_PIN3, output); // Why is the macro name red...


  return 1; // no way to error check?
}

int initializeStepperMotor() {
  // When you start machine, have to establish the 0 for the stepper to do this:
  // measuring stepper's current and turn it in a known direction  until we hit mechanical nstop.
  // Once we reach that current spikes up and know we hit 0.

  // https://www.instructables.com/id/Control-DC-and-stepper-motors-with-L298N-Dual-Moto/
  // Recommends example code from Stepper library: stepper_oneRevolution.ino
  // CONNECT
  O2Valve.setSpeed(60); // 60 rpm
  direction = -1; // -1 for ccw, 1 for cw

  // ZERO MOTOR (if the pin goes high, we are zero'd?)
  zeroSense = digitalRead(STEP_MOTOR_ZERO_PIN)
  while zeroSense {
    myStepper.step(direction);
    zeroSense = digitalRead(STEP_MOTOR_ZERO_PIN);
    delay(1); // lets the motor settle, may be unncessary
  }

  return 1; // we need error checking
}