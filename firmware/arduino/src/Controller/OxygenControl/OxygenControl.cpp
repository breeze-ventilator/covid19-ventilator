#include "OxygenControl.h"

OxygenControl::OxygenControl()
: oxygenValveStepper(OXYGEN_VALVE_PIN0, OXYGEN_VALVE_PIN1, OXYGEN_VALVE_PIN2,
          OXYGEN_VALVE_PIN3, OXYGEN_VALVE_CURRENT_SENSE_PIN,
          OXYGEN_VALVE_ACTIVATE1_PIN, OXYGEN_VALVE_ACTIVATE2_PIN)//,
  // pid(&_oxygenActualConcentration, &_valveSetPoint, &_oxygenSetConcentration,
  //     OXYGEN_KP, OXYGEN_KI, OXYGEN_KD, DIRECT)
{
	_lastOxygenControlTime = 0;
}

void OxygenControl::begin() {
	oxygenValveStepper.begin();
  oxygenValveStepper.moveToZeroPosition();
	// pid.SetSampleTime(OXYGEN_PID_TIME);
  // pid.SetMode(AUTOMATIC);
  // pid.SetOutputLimits(-100,100); // TODO: this is in steps, who knows
}

void OxygenControl::control(float desiredFiO2, float oxygenConcentration) {
	// only control oxygen if in range
	if (abs(oxygenConcentration - desiredFiO2) < OXYGEN_DESIRED_ACCURACY) {
		if (desiredFiO2 < oxygenConcentration) {
			oxygenValveStepper.move(VALVE_STEP_SIZE);
		}
		else {
			oxygenValveStepper.move(-VALVE_STEP_SIZE);
		}
	}

	// _oxygenSetConcentration = setOxygenConcentration;
	// _oxygenActualConcentration = actualOxygenConcentration;
}

int OxygenControl::isTimeToControlOxygen() {
  return isTime(_lastOxygenControlTime, TIME_BETWEEN_OXYGEN_CONTROLS);
}