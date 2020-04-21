#include "Parameters.h"

// mode

Parameters::Parameters() {
  currentMode = OFF_MODE;
  newParamsHaveArrived = false;
}

void Parameters::getNewParameters(uint8_t parametersBuffer[PARAMETER_BYTE_LENGTH]) {
  // ignores checksum at position 1
  _newMode = parametersBuffer[1];
  _newFiO2 = parametersBuffer[2];
  _newPEEP = (uint16_t) parametersBuffer[3] * CENTIMETERS_TO_MILIMETERS;
  _newInspiratoryPressure = (uint16_t) parametersBuffer[4] * CENTIMETERS_TO_MILIMETERS;
  _newSensitivity = -1 * (int16_t) parametersBuffer[5]; // L
  uint8_t rate = parametersBuffer[6];
  uint8_t inspiratoryTimePercentage = parametersBuffer[7];
  _newFlowCyclingOffPercentage = parametersBuffer[8] / 100.0;
  _newApneaTime = (uint16_t) parametersBuffer[9] * SECONDS_TO_MILLISECONDS;
  _newRiseTime = (uint16_t) parametersBuffer[10] * TENTH_OF_SECOND_TO_MILISECONDS;
  _newHighInspiratoryPressureAlarm = (uint16_t) parametersBuffer[11] * CENTIMETERS_TO_MILIMETERS;
  _newLowExpiratoryPressureAlarm = (uint16_t) parametersBuffer[12] * CENTIMETERS_TO_MILIMETERS;
  
  if (_newMode == PRESSURE_CONTROL_MODE) {
    float breathTime = 1.0/((float)rate) * MINUTES_TO_MILLISECONDS;
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

  Serial.println(currentMode);
  Serial.println(currentFiO2);
  Serial.println(currentInspiratoryTime);
  Serial.println(currentMaxExpiratoryTime);
  Serial.println(currentInspiratoryPressure);
  Serial.println(currentPEEP);
  Serial.println(currentSensitivity);
  Serial.println(currentApneaTime);
  Serial.println(currentFlowCyclingOffPercentage);
  Serial.println(currentRiseTime);
  Serial.println(currentHighInspiratoryPressureAlarm);
  Serial.println(currentLowExpiratoryPressureAlarm);

  newParamsHaveArrived = false;
	return;
}