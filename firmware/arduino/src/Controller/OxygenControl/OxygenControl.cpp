#include "OxygenControl.h"

OxygenControl::OxygenControl()
: _oxygenValveStepper(OXYGEN_VALVE_MOTOR_INTERFACE_TYPE,
                    OXYGEN_VALVE_PIN0,
                    OXYGEN_VALVE_PIN1,
                    OXYGEN_VALVE_PIN2,
                    OXYGEN_VALVE_PIN2,
                    OXYGEN_VALVE_LIMIT_SWITCH_PIN,
                    OXYGEN_VALVE_MAX_STEPPER_SPEED,
                    OXYGEN_VALVE_STEPPER_ACCELERATION,
                    OXYGEN_VALVE_ENABLE1_PIN,
                    OXYGEN_VALVE_ENABLE2_PIN)
{

}

void OxygenControl::begin() {
	_oxygenValveStepper.begin();
	int error = _oxygenValveStepper.moveToZeroPosition(OXYGEN_CONTROL_ZEROING_WAIT_TIME);
}

void OxygenControl::control(long value) {
	/*
	If in inhalation mode, should be in PID state

	If in exhalation mode, turn it off
	*/
	Serial.println(_oxygenValveStepper.getCurrentPosition());
	_oxygenValveStepper.move(value);
}