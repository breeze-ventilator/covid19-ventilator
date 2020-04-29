#ifndef OXYGEN_VALVE_STEPPER
#define OXYGEN_VALVE_STEPPER

#include <AccelStepper.h> // Include the AccelStepper library:
#include "Arduino.h"
#include "../../../Defs/errors.h"
#include <math.h>

#define CURRENT_TRIGGER 1
#define STEPPER_MAX_SPEED 1000
#define STEPPER_ACCELERATION 500
#define MAX_STEPS 2000 // 10 revolutions, 200 steps per revolution

class OxygenValveStepper {
  public:
	  OxygenValveStepper(int pin0,
                       int pin1,
                       int pin2,
                       int pin3,
                       int currentSensePin,
                       int oxygenActivate1Pin,
                       int oxygenActivate2Pin);
    void begin();
    void moveToZeroPosition();
    void move(long desiredSteps);
    void runOneStepIfRequired();
    void activate();
    void deactivate();
    
  private:
	  AccelStepper stepper;
    int _currentSensePin;
    int _maxStepperSpeed;
    int _stepperAcceleration;
    int _oxygenActivate1Pin;
    int _oxygenActivate2Pin;

    bool _moveComplete = false;
};

#endif