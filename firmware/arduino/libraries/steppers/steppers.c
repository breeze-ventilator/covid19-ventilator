#include <AccelStepper.h> // Include the AccelStepper library:
#include "steppers.h"

#define ACCEL_STEPPER_MOTOR_INTERFACE_TYPE 4 //leave this here
#define STEPS_PER_REVOLUTION 200 //leave here
#define MAX_STEPPER_SPEED 200.0
#define STEPPER_ACCELERATION 100.0

// Define the Pins used
#define HOME_SWITCH 9 // Pin 9 connected to Home Switch (MicroSwitch) //move to other file?

#define AMBIENT_PRESSURE 14.6959
#define FLOW_COEFFICIENT 1

// Create a new instance of the AccelStepper class:
AccelStepper oxygenStepper = AccelStepper(ACCEL_STEPPER_MOTOR_INTERFACE_TYPE, OXYGEN_CONT_PIN0, OXYGEN_CONT_PIN1, OXYGEN_CONT_PIN2, OXYGEN_CONT_PIN3);

int initializeOxygenStepper(int maxWaitTime) { 
  pinMode(HOME_SWITCH, INPUT_PULLUP);
  oxygenStepper.setMaxSpeed(MAX_STEPPER_SPEED); // Slower to get better accuracy
  oxygenStepper.setAcceleration(STEPPER_ACCELERATION;

  // enable the power to the stepper at about half power
  analogWrite(O2_ENABLE1_PIN, 100);
  analogWrite(O2_ENABLE2_PIN, 100);

  return moveOxygenStepperToZeroPosition(maxWaitTime);
}

int moveOxygenStepperToZeroPosition(int maxWaitTime){
  int count = 0;
  
  // Make the Stepper move CW until the switch is activated   
  while (digitalRead(HOME_SWITCH)) {
    oxygenStepper.moveTo(oxygenStepper.currentPosition() + 1);  // Set the position to move to
    oxygenStepper.run(); // Start moving the stepper
    delay(5);
    count += 5;
    if (count > maxWaitTime) {
      return TIMEOUT_ERROR;
    }
  }
  oxygenStepper.setCurrentPosition(0);  // Set the current position as zero for now
  return 1;
}

void setOxygenFlow(float flow, float pressure) {
  float highFlow = (pressure/AMBIENT_PRESSURE) * flow;
  oxygenStepper.moveTo(floor(FLOW_COEFFICIENT * highFlow));
  oxygenStepper.run();
  return;
}

// pressure in psi = 0.1354*(volts) + 1.01