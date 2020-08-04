#include "Data.h"

Data::Data()
  : _pressureValues(PRESSURE_HISTORY_LENGTH_FOR_PID),
    _flowValues(FLOW_HISTORY_LENGTH),
    _oxygenValues(OXYGEN_HISTORY_LENGTH)
{
  tidalVolume = 0.0;
}

void Data::saveFlowReading(float flowValue) {
  _flowValues.push(flowValue);
}

void Data::updateTidalVolume(float flowValue, float delta_time) {
  tidalVolume += flowValue*delta_time;
}

void Data::saveMainPressureReading(float pressureValue) {
  // for PID
  _pressureValues.push(pressureValue);
}

float Data::getMainPressureAverageForPID() {
  return _pressureValues.getMean();
}

float Data::getFlowRecentHistoryAverage() {
  return _flowValues.getMean();
}

void Data::saveBatteryPercentage(unsigned int newBatteryPercentage) {
  batteryPercentage = newBatteryPercentage;
}

void Data::saveOxygenReading(float newOxygenReading) {
  _oxygenValues.push(newOxygenReading);
}

float Data::getOxygenRecentHistoryAverage() {
  return _oxygenValues.getMean();
}

// when breath finished
void Data::resetTidalVolume() {
  tidalVolume = 0.0;
}