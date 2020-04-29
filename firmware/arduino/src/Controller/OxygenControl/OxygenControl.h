#ifndef OXYGEN_CONTROL_H
#define OXYGEN_CONTROL_H

#include "Arduino.h"
#include "OxygenValveStepper/OxygenValveStepper.h"
#include <PID_v1.h>

#define OXYGEN_VALVE_PIN0 42
#define OXYGEN_VALVE_PIN1 44
#define OXYGEN_VALVE_PIN2 43
#define OXYGEN_VALVE_PIN3 41
#define OXYGEN_VALVE_CURRENT_SENSE_PIN 2
#define OXYGEN_VALVE_ACTIVATE1_PIN 2
#define OXYGEN_VALVE_ACTIVATE2_PIN 3

#define OXYGEN_KP 1
#define OXYGEN_KI 1
#define OXYGEN_KD 1
#define OXYGEN_PID_TIME 100


class OxygenControl {
  public:
	  OxygenControl();
    void begin();
    void control(float setOxygenConcentration, float actualOxygenConcentration);

  private:
    OxygenValveStepper oxygenValveStepper;
    PID pid;
    double _oxygenActualConcentration = 0;
    double _valveSetPoint = 0;
    double _oxygenSetConcentration = 0;
};

#endif