#include "Parameters.h"

Parameters::Parameters() {
}

/* 
Position   PARAM
  1       Checksum 
  2       Mode (1, 2, or 3)
  3       Exhalation time (tells us the rate if controlled)
  4       FiO2
  5       Inspiration time
  6       PEEP (exhalation pressure)
  7       Inhalation pressure
*/
void Parameters::getNewParameters(String receivedString) {
	_newMode = piString.charAt(1);
  _newFiO2 = piString.charAt(2);
  _newInspiratoryTime = piString.charAt(3);
  _newExpiratoryTime = piString.charAt(4);
  _newPeakInspiratoryPressure = piString.charAt(5);
  _newPeakExpiratoryPressure = piString.charAt(6);
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
	currentPeakExpiratoryPressure = _newPeakExpiratoryPressure;
	currentSensitivity = _newSensitivity;
	return;
}