#include "Data.h"

Data::Data()
  : _pressureValues(PRESSURE_HISTORY_LENGTH_FOR_PID)
{
  flowIntegral = 0;
}

void Data::saveFlowReading(float flowValue, float delta_time) {
  flowIntegral += flowValue*delta_time;
}

void Data::saveMainPressureReading(unsigned int pressureValue) {
  // for PID
  _pressureValues.push(pressureValue);

  // for Pi
  pressureSum += pressureValue;
  numPressureMeasurements++;
}

float Data::getMainPressureAverageForPID() {
  return _pressureValues.getMean();
}

void Data::saveBatteryPercentage(unsigned int newBatteryPercentage) {
  batteryPercentage = newBatteryPercentage;
}

void Data::saveOxygenPressureReading(unsigned int pressureValue) {
  // TODO
}

void Data::resetPiDataExceptFlow() {
  pressureSum = 0;
  numPressureMeasurements = 0;
  numFlowErros = 0;
  numPressureErrors = 0;
  batteryPercentage = 0;
  return;
}

// when breath finished
void Data::resetPiFlowData() {
  flowIntegral = 0.0;
}