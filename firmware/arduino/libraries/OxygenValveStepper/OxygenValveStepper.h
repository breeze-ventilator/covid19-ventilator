#ifndef SENSORS_H
#define SENSORS_H

#define AMBIENT_PRESSURE 15

class OxygenValveStepper {
  public:
	  OxygenValveStepper(int motorInterfaceType, int pin0, int pin1,
      int pin2, int pin3, int limitSwitchPin, int maxStepperSpeed, int stepperAcceleration,
      int oxygenEnable1Pin, int oxygenEnable2Pin);
    void moveOxygenStepperToZeroPosition(int maxWaitTime);
    void stepOxygenFlow(float flow, float pressure);
    void runOneStep();
    
  private:
	  AccelStepper _oxygenStepper;
    int _limitSwitchPin;
};

#endif