#include "OxygenValveStepper.h"

OxygenValveStepper::OxygenValveStepper(int pin0,
                                       int pin1,
                                       int pin2,
                                       int pin3,
                                       int currentSensePin,
                                       int oxygenActivate1Pin,
                                       int oxygenActivate2Pin)
  : stepper(AccelStepper::FULL4WIRE, pin0, pin1, pin2, pin3)
{
  _currentSensePin = currentSensePin;
  _oxygenActivate1Pin = oxygenActivate1Pin;
  _oxygenActivate2Pin = oxygenActivate2Pin;
}

void OxygenValveStepper::begin() {
  pinMode(_oxygenActivate1Pin, OUTPUT);
  pinMode(_oxygenActivate2Pin, OUTPUT);
  stepper.setMaxSpeed(STEPPER_MAX_SPEED); // Slower to get better accuracy
  stepper.setAcceleration(STEPPER_ACCELERATION);
}

void OxygenValveStepper::moveToZeroPosition() {
  initialActivate();
  
  // jam the stepper to the end until we're sure it's at 0
  int32_t newPosition = stepper.currentPosition() - MAX_STEPS;
  stepper.runToNewPosition(newPosition);
  
  // could alternatively use a limit switch to avoid jamming
  // ^ could use movingAverage(analogRead(_currentSensePin)*5.319/1024) < CURRENT_TRIGGER

  stepper.setCurrentPosition(0);  // Set the current position as zero
  deactivate();
}

void OxygenValveStepper::initialActivate() {
  // we activate/deactivate the stepper to avoid overheating

  // enable the power to the stepper at about half power
  analogWrite(_oxygenActivate1Pin, 120);
  analogWrite(_oxygenActivate2Pin, 120);
}

void OxygenValveStepper::activate() {
  // we activate/deactivate the stepper to avoid overheating

  // enable the power to the stepper at about half power
  analogWrite(_oxygenActivate1Pin, 150);
  analogWrite(_oxygenActivate2Pin, 150);
}

void OxygenValveStepper::deactivate() {
  // let the stepper rest to avoid overheating
  digitalWrite(_oxygenActivate1Pin, LOW);
  digitalWrite(_oxygenActivate2Pin, LOW);
}

void OxygenValveStepper::move(long desiredSteps) {
  activate();

  long steps = max(-stepper.currentPosition(), desiredSteps); // don't go past 0
  steps = min(steps, MAX_STEPS - stepper.currentPosition()); // don't go past the end
  if (steps != 0) {
    stepper.move(steps);
    _moveComplete = false;
  }
}

void OxygenValveStepper::runOneStepIfRequired(){
  if (!_moveComplete) {
    if (stepper.distanceToGo() == 0)
    {
      deactivate(); // deactivate when we're done moving
      _moveComplete = true;
    }
    else
    {
      stepper.run();
    }
  }
}

long OxygenValveStepper::getCurrentPosition() {
  return stepper.currentPosition();
}