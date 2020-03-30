/*
  Turns on or off the arduino alarm.

  @params:
    bool set - Turn on or off alarm.
*/
#include "control.h"

int turnOffAlarm() {
  // Turn Off Alarm
  return;
}

void keepAlarmRunningForever() {
  while(1) {
    ;
  }
  return;
}

void inhalationControl(struct Data *data, struct Parameters currentParams) {
  // modify RPM of fan to get desired pressure (peak pressure)
  
}

void exhalationControl(struct Data *data, struct Parameters currentParams) {
  // modify RPM of fan to get desired pressure (PEEP pressure)
}

void oxygenControl(struct Data *data, struct Parameters currentParams) {
  // modify steps on stepper motor to get desired flow rate (which then gives concentration)
}

