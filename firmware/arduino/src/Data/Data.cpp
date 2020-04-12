#include "Data.h"

Data::Data()
  : _pressureValues(PRESSURE_HISTORY_LENGTH_FOR_PID),
    _flowValues(FLOW_HISTORY_LENGTH)
{
  tidalVolume = 0;
}

void Data::saveFlowReading(float flowValue, float delta_time) {
  _flowValues.push(flowValue);
  tidalVolume += flowValue*delta_time;
}

void Data::saveMainPressureReading(unsigned int pressureValue) {
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

void Data::saveOxygenPressureReading(unsigned int pressureValue) {
  // TODO
}

// when breath finished
void Data::resetTidalVolume() {
  tidalVolume = 0.0;
}