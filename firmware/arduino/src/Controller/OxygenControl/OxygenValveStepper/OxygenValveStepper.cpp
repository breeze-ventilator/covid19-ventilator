#include "OxygenValveStepper.h"

// #define ACCEL_STEPPER_MOTOR_INTERFACE_TYPE 4 //leave this here
// #define STEPS_PER_REVOLUTION 200 //leave here
// #define MAX_STEPPER_SPEED 200.0
// #define STEPPER_ACCELERATION 100.0

// // Define the Pins used
// #define HOME_SWITCH 9 // Pin 9 connected to Home Switch (MicroSwitch) //move to other file?

// #define AMBIENT_PRESSURE 14.6959
// #define FLOW_COEFFICIENT 1

OxygenValveStepper::OxygenValveStepper(int motorInterfaceType, int pin0, int pin1,
      int pin2, int pin3, int limitSwitchPin, int maxStepperSpeed, int stepperAcceleration,
      int oxygenEnable1Pin, int oxygenEnable2Pin)  
  : _oxygenStepper(motorInterfaceType, pin0, pin1, pin2, pin3)
{
  _limitSwitchPin = limitSwitchPin;
  _oxygenEnable1Pin = oxygenEnable1Pin;
  _oxygenEnable2Pin = oxygenEnable2Pin;
  _maxStepperSpeed = maxStepperSpeed;
  _stepperAcceleration = stepperAcceleration;
}

void OxygenValveStepper::begin() {
  pinMode(_limitSwitchPin, INPUT_PULLUP); // TODO: simon need better naming here
  
  _oxygenStepper.setMaxSpeed(_maxStepperSpeed); // Slower to get better accuracy
  _oxygenStepper.setAcceleration(_stepperAcceleration);
  
  // enable the power to the stepper at about half power
  analogWrite(_oxygenEnable1Pin, 100);
  analogWrite(_oxygenEnable2Pin, 100);
}

int OxygenValveStepper::moveToZeroPosition(int maxWaitTime) {
  int count = 0;
  // while (!digitalRead(_limitSwitchPin)){ // 1 default, 0 when zeroed
  //   _oxygenStepper.moveTo(_oxygenStepper.currentPosition() + 1);  // Set the position to move to
  //   _oxygenStepper.run(); // Start moving the stepper
  //   delay(5);
  //   count += 5;
  //   if (count > maxWaitTime) {
  //     return TIMEOUT_ERROR;
  //   } else {
  //     return 1;
  //   }
  // }
  // count = 0;
  // Make the Stepper move CCW until the switch is activated   
  while (digitalRead(_limitSwitchPin)) {
    _oxygenStepper.moveTo(_oxygenStepper.currentPosition() - 1);  // Set the position to move to
    _oxygenStepper.run(); // Start moving the stepper
    delay(5);
    count += 5;
    if (count > maxWaitTime) {
      return TIMEOUT_ERROR;
    }
  }
  _oxygenStepper.setCurrentPosition(0);  // Set the current position as zero for now
  return 1;
}

void OxygenValveStepper::move(long value) {
  _oxygenStepper.moveTo(value);
  _oxygenStepper.run(); //this only moves one step soooo
 
  return; //need to calll this function often like 100 hz
}

void OxygenValveStepper::runOneStep(){
  _oxygenStepper.run();
}

long OxygenValveStepper::getCurrentPosition() {
  return _oxygenStepper.currentPosition();
}

// pressure in psi = 0.1354*(volts) + 1.01