#include "OxygenControl.h"

OxygenControl::OxygenControl()
: oxygenValveStepper(OXYGEN_VALVE_PIN0, OXYGEN_VALVE_PIN1, OXYGEN_VALVE_PIN2,
          OXYGEN_VALVE_PIN3, OXYGEN_VALVE_CURRENT_SENSE_PIN,
          OXYGEN_VALVE_ENABLE1_PIN, OXYGEN_VALVE_ENABLE2_PIN)
{
	_lastOxygenControlTime = 0;
}

void OxygenControl::begin() {
	oxygenValveStepper.begin();
  oxygenValveStepper.moveToZeroPosition();
}

void OxygenControl::zero() {
  oxygenValveStepper.moveToZeroPosition();
}

void OxygenControl::control(float desiredFiO2, Data &data) {
	Serial.print(data.getOxygenRecentHistoryAverage());
  Serial.print(" ");
	Serial.println(oxygenValveStepper.getCurrentPosition());
	if (isTimeToControlOxygen()) {
		// only control oxygen if required
		float oxygenConcentration = data.getOxygenRecentHistoryAverage();
		if (abs(oxygenConcentration - desiredFiO2) > OXYGEN_DESIRED_ACCURACY) {
			if (oxygenConcentration < desiredFiO2) {
				oxygenValveStepper.move(VALVE_STEP_SIZE);
			}
			else {
				oxygenValveStepper.move(-VALVE_STEP_SIZE);
			}
		}
		_lastOxygenControlTime = millis();
	}
	oxygenValveStepper.runOneStepIfRequired();
}

int OxygenControl::isTimeToControlOxygen() {
  return isTime(_lastOxygenControlTime, TIME_BETWEEN_OXYGEN_CONTROLS);
}