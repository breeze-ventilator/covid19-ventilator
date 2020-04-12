#ifndef OXYGEN_VALVE_STEPPER
#define OXYGEN_VALVE_STEPPER

#include <AccelStepper.h> // Include the AccelStepper library:
#include "Arduino.h"
#include "../../../Defs/errors.h"

class OxygenValveStepper {
  public:
	  OxygenValveStepper(int motorInterfaceType, int pin0, int pin1,
      int pin2, int pin3, int limitSwitchPin, int maxStepperSpeed, int stepperAcceleration,
      int oxygenEnable1Pin, int oxygenEnable2Pin);
    void begin();
    int moveToZeroPosition(int maxWaitTime);
    void move(long value);
    void runOneStep();
    long getCurrentPosition();
    
  private:
	  AccelStepper _oxygenStepper;
    int _limitSwitchPin;
    int _maxStepperSpeed;
    int _stepperAcceleration;
    int _oxygenEnable1Pin;
    int _oxygenEnable2Pin;
};

#endif