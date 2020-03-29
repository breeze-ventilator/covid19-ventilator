#include <Stepper.h>
#include <Servo.h>

// these need to be global
Servo blowerFan;  
Servo airIntake;

#define STEPS_PER_REVOLUTION  100 // this is dependent on the motor and should be updated, will move to init.h 
Stepper O2Valve(STEPS_PER_REVOLUTION, O2_CONT_PIN0, O2_CONT_PIN1, O2_CONT_PIN2, O2_CONT_PIN3);

/*
  Initializes the pins for the arduino.
*/
void initializePins() {
  // https://www.arduino.cc/en/Tutorial/DigitalPins

  // inputs/measurements
  pinMode(PRESSURE_PIN, INPUT);
  pinMode(FLOW_PIN, INPUT);
  pinMode(BATTERY_PIN, INPUT); // TODO: What is the battery pin?
  pinMode(FAN_SENSOR_PIN, INPUT); // TODO: Clarify with Simon how fan pins work?

  // outputs/controls
  pinMode(ALARM_PIN, OUTPUT);
  pinMode(BLOWER_PIN, OUTPUT); // TODO: Are we controlling two fans?
  pinMode(O2_CONTROL_PIN0, OUTPUT);
  pinMode(O2_CONTROL_PIN1, OUTPUT);
  pinMode(O2_CONTROL_PIN2, OUTPUT);
  pinMode(O2_CONTROL_PIN3, OUTPUT);
  pinMode(AIR_CONTROL_PIN, OUTPUT);
}

/*
  Initializes Stepper for O2 Valve.
*/
int initializeStepperMotor() {
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

    if (count == STEPPER_INITIALIZATION_TIMEOUT){
      return 0;
    }
  }

  return 1; // we need error checking?
}


int initializeServos() {
  // See Arduino example file in IDE: Examples > Servo > Knob
  blowerFan.attach(BLOWER_PIN);
  blowerFan.write(BLOW_FAN_INITIAL_POSITION); //// https://www.arduino.cc/en/Reference/ServoWrite

  airIntake.attach(AIR_CONTROL_PIN);
  airIntake.write(AIR_INTAKE_INITIAL_POSITION);

  // TODO: Need to set the default position. Do these needs to be zero'd?

  return 1;
}
