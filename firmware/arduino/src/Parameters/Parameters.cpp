#include "Parameters.h"

// mode
#define WAITING_FOR_PARAMETERS 0

Parameters::Parameters() {
  currentMode = WAITING_FOR_PARAMETERS;
  newParamsHaveArrived = false;
}

void Parameters::getNewParameters(String receivedString) {
	_newMode = receivedString.charAt(1);
  _newFiO2 = receivedString.charAt(2);
  _newInspiratoryTime = receivedString.charAt(3);
  _newExpiratoryTime = receivedString.charAt(4);
  _newPeakInspiratoryPressure = receivedString.charAt(5);
  _newPEEP = receivedString.charAt(6);
  _newSensitivity = receivedString.charAt(7);
  
  newParamsHaveArrived = true;
	return;
}

// deep copy of new parameters to current parameters
void Parameters::updateCurrentParameters() {
	currentMode = _newMode;
	currentFiO2 = _newFiO2;
	currentInspiratoryTime = _newInspiratoryTime;
	currentExpiratoryTime = _newExpiratoryTime;
	currentPeakInspiratoryPressure = _newPeakInspiratoryPressure;
	currentPEEP = _newPEEP;
	currentSensitivity = _newSensitivity;

  newParamsHaveArrived = false;
	return;
}