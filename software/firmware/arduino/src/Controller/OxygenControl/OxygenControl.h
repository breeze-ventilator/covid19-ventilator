#ifndef OXYGEN_CONTROL_H
#define OXYGEN_CONTROL_H

#include "Arduino.h"
#include "OxygenValveStepper/OxygenValveStepper.h"
#include <PID_v1.h>

#define OXYGEN_VALVE_PIN0 41
#define OXYGEN_VALVE_PIN1 43
#define OXYGEN_VALVE_PIN2 44
#define OXYGEN_VALVE_PIN3 45
#define OXYGEN_VALVE_CURRENT_SENSE_PIN 2
#define OXYGEN_VALVE_ENABLE1_PIN 2
#define OXYGEN_VALVE_ENABLE2_PIN 3

#define OXYGEN_KP 1
#define OXYGEN_KI 1
#define OXYGEN_KD 1
#define OXYGEN_PID_TIME 100
#define OXYGEN_DESIRED_ACCURACY 3 // %
#define VALVE_STEP_SIZE 2 // 0.36 degrees
#define TIME_BETWEEN_OXYGEN_CONTROLS 500

#include "../../Helpers/helpers.h"
#include "../../Data/Data.h"

class OxygenControl {
  public:
	  OxygenControl();
    void begin();
    void control(float desiredFiO2, Data &data);
    void zero();

  private:
    OxygenValveStepper oxygenValveStepper;
    unsigned long _lastOxygenControlTime;
    int isTimeToControlOxygen();
    
};

#endif