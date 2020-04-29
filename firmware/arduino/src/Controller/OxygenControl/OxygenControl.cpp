#include "OxygenControl.h"

OxygenControl::OxygenControl()
: oxygenValveStepper(OXYGEN_VALVE_PIN0, OXYGEN_VALVE_PIN1, OXYGEN_VALVE_PIN2,
          OXYGEN_VALVE_PIN3, OXYGEN_VALVE_CURRENT_SENSE_PIN,
          OXYGEN_VALVE_ACTIVATE1_PIN, OXYGEN_VALVE_ACTIVATE2_PIN),
  pid(&_oxygenActualConcentration, &_valveSetPoint, &_oxygenSetConcentration,
      OXYGEN_KP, OXYGEN_KI, OXYGEN_KD, DIRECT)
{

}

void OxygenControl::begin() {
	oxygenValveStepper.begin();
  oxygenValveStepper.moveToZeroPosition();
	pid.SetSampleTime(OXYGEN_PID_TIME);
  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(0,4000); // this is in steps, who knows
}

void OxygenControl::control(float setOxygenConcentration, float actualOxygenConcentration) {
	/*
	If in inhalation mode, should be in PID state

	If in exhalation mode, turn it off

    Should only move if it has 10 steps to go
	*/

	_oxygenSetConcentration = setOxygenConcentration;
	_oxygenActualConcentration = actualOxygenConcentration;
	// Serial.println(oxygenValveStepper.getCurrentPosition());
	int val = 2;
	oxygenValveStepper.move(val);
}