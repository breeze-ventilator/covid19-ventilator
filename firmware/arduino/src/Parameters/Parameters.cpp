#include "Parameters.h"

// mode

Parameters::Parameters() {
  currentMode = OFF_MODE;
  newParamsHaveArrived = false;
}

void Parameters::getNewParameters(uint8_t parametersBuffer[PARAMETER_BYTE_LENGTH]) {
  // ignores checksum at char 0
  _newMode = parametersBuffer[2];
  _newFiO2 = parametersBuffer[3];
  _newPEEP = (uint16_t) parametersBuffer[4] * CENTIMETERS_TO_MILIMETERS;
  _newInspiratoryPressure = (uint16_t) parametersBuffer[5] * CENTIMETERS_TO_MILIMETERS;
  _newSensitivity = parametersBuffer[6];
  uint8_t rate = parametersBuffer[7];
  uint8_t inspiratoryTimePercentage = parametersBuffer[8];
  _newFlowCyclingOffPercentage = parametersBuffer[9];
  _newApneaTime = parametersBuffer[10];
  _newRiseTime = (uint16_t) parametersBuffer[11] * TENTH_OF_SECOND_TO_MILISECONDS;
  _newHighInspiratoryPressureAlarm = (uint16_t) parametersBuffer[12] * CENTIMETERS_TO_MILIMETERS;
  _newLowExpiratoryPressureAlarm = (uint16_t) parametersBuffer[13] * CENTIMETERS_TO_MILIMETERS;
  
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