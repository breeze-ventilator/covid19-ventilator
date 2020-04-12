#include "Parameters.h"

// mode

Parameters::Parameters() {
  currentMode = OFF_MODE;
  newParamsHaveArrived = false;
}

void Parameters::getNewParameters(String receivedString) {
  // ignores checksum at char 0
  _newMode = (uint8_t) receivedString.charAt(2);
  _newFiO2 = (uint8_t) receivedString.charAt(3);
  _newPEEP = (uint8_t) receivedString.charAt(4);
  _newInspiratoryPressure = (uint8_t) receivedString.charAt(5);
  _newSensitivity = (uint8_t) receivedString.charAt(6);
  uint8_t rate = (uint8_t) receivedString.charAt(7);
  uint8_t inspiratoryTimePercentage = (uint8_t) receivedString.charAt(8);
  _newFlowCyclingOffPercentage = (uint8_t) receivedString.charAt(9);
  _newApneaTime = (uint8_t) receivedString.charAt(10);
  _newRiseTime = (uint16_t) receivedString.charAt(11);;
  _newHighInspiratoryPressureAlarm = (uint8_t) receivedString.charAt(12);
  _newLowExpiratoryPressureAlarm = (uint8_t) receivedString.charAt(13);
  
  if (_newMode == PRESSURE_CONTROL_MODE) {
    float breathTime = 1.0/((float)rate) * SECONDS_TO_MILLISECONDS;
    _newInspiratoryTime = breathTime*inspiratoryTimePercentage/100.0;
    _newMaxExpiratoryTime = breathTime - _newInspiratoryTime;
  }
  
  newParamsHaveArrived = true;
	return;
}

// deep copy of new parameters to current parameters
void Parameters::updateCurrentParameters() {
	currentMode = _newMode;
  currentFiO2 = _newFiO2;
  currentInspiratoryTime = _newInspiratoryTime;
  currentMaxExpiratoryTime = _newMaxExpiratoryTime;
  currentInspiratoryPressure = _newInspiratoryPressure;
  currentPEEP = _newPEEP;
  currentSensitivity = _newSensitivity;
  currentApneaTime = _newApneaTime;
  currentFlowCyclingOffPercentage = _newFlowCyclingOffPercentage;
  currentRiseTime = _newRiseTime;
  currentHighInspiratoryPressureAlarm = _newHighInspiratoryPressureAlarm;
  currentLowExpiratoryPressureAlarm = _newLowExpiratoryPressureAlarm;

  newParamsHaveArrived = false;
	return;
}