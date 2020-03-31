#include "Parameters.h"

// mode
#define WAITING_FOR_PARAMETERS 0

Parameters::Parameters() {
  currentMode = WAITING_FOR_PARAMETERS;
}

void Parameters::getNewParameters(String receivedString) {
	_newMode = piString.charAt(1);
  _newFiO2 = piString.charAt(2);
  _newInspiratoryTime = piString.charAt(3);
  _newExpiratoryTime = piString.charAt(4);
  _newPeakInspiratoryPressure = piString.charAt(5);
  _newPEEP = piString.charAt(6);
  _newSensitivity = piString.charAt(7);
	return;
}

// deep copy of new parameters to current parameters
void Parameters::updateCurrentParameters() {
	currentMode = _newMode;
	currentMiO2 = _newFiO2;
	currentInspiratoryTime = _newInspiratoryTime;
	currentMxpiratoryTime = _newExpiratoryTime;
	currentPeakInspiratoryPressure = _newPeakInspiratoryPressure;
	currentPEEP = _newPEEP;
	currentSensitivity = _newSensitivity;
	return;
}