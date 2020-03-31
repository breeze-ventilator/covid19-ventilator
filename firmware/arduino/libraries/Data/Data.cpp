#include "Data.h"
#include <list>

Data::Data(int flowHistoryLengthForPID, int pressureHistoryLengthForPID) {
  flowHistoryLengthForPID = flowHistoryLengthForPID;
  pressureHistoryLengthForPID = pressureHistoryLengthForPID;
}

void Data::saveFlowReading(float flowValue, float delta_time) {
  flowValues.push_back(flowValue);
  if (flowValues.size() > flowHistoryLengthForPID) {
    flowValues.pop_front();
  }
  flowIntegral += flowValue*delta_time;
}

void Data::saveMainPressureReading(unsigned int pressureValue) {
  pressureValues.push_back(pressureValue);
  if (pressureValues.size() > pressureHistoryLengthForPID) {
    pressureValues.pop_front();
  }
  pressureSum += pressureValue;
  numPressureMeasurements += 
}

void Data::saveBatteryPercentage(unsigned int batteryPercentage) {
  batteryPercentage = batteryPercentage;
}

void Data::saveOxygenPressureReading(unsigned int pressureValue) {
  // TODO
}

void Data::resetPiDataExceptFlow() {
  pressureSum = 0;
  numFlowMeasurements = 0;
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