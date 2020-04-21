#include "OxygenControl.h"

OxygenControl::OxygenControl()
: _oxygenValveStepper(OXYGEN_VALVE_MOTOR_INTERFACE_TYPE,
                    OXYGEN_VALVE_PIN0,
                    OXYGEN_VALVE_PIN1,
                    OXYGEN_VALVE_PIN2,
                    OXYGEN_VALVE_PIN2,
                    OXYGEN_VALVE_CURRENT_SENSE_PIN,
                    OXYGEN_VALVE_MAX_STEPPER_SPEED,
                    OXYGEN_VALVE_STEPPER_ACCELERATION,
                    OXYGEN_VALVE_ENABLE1_PIN,
                    OXYGEN_VALVE_ENABLE2_PIN),
    _oxygenControl(&_oxygenActualConcentration, &_valveSetPoint, &_oxygenSetConcentration,
                    OXYGEN_KP, OXYGEN_KI, OXYGEN_KD, DIRECT) // PID
{

}

void OxygenControl::begin() {
	_oxygenValveStepper.begin();
	int error = _oxygenValveStepper.moveToZeroPosition(OXYGEN_CONTROL_ZEROING_WAIT_TIME);
	_oxygenControl.SetSampleTime(OXYGEN_PID_TIME);
  _oxygenControl.SetMode(AUTOMATIC);
  _oxygenControl.SetOutputLimits(0,4000); // this is in steps, who knows
}

void OxygenControl::control(int setOxygenConcentration, int actualOxygenConcentration) {
	/*
	If in inhalation mode, should be in PID state

	If in exhalation mode, turn it off

    Should only move if it has 10 steps to go
	*/

	_oxygenSetConcentration = (float) setOxygenConcentration;
	_oxygenActualConcentration = (float) actualOxygenConcentration;
	// Serial.println(_oxygenValveStepper.getCurrentPosition());
	int val = 2;
	_oxygenValveStepper.move(val);
}