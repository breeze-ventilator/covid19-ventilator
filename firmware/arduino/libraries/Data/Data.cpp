#include "Data.h"
#include "OxygenValveStepper.h"
#include "AirIntakeServo.h"
#include "BlowerFanServo.h"
#include <list>

Data::Data(int flowHistoryLengthForPID, int pressureHistoryLengthForPID) {
  _flowHistoryLengthForPID = flowHistoryLengthForPID;
  _pressureHistoryLengthForPID = pressureHistoryLengthForPID;
}

void Data::saveFlowReading(float flowValue) {
  _flowValues.push_back(flowValue);
  if (_flowValues.size() > _flowHistoryLengthForPID) {
    _flowValues.pop_front();
  }
}

void Data::saveMainPressureReading(unsigned int pressureValue) {
  _pressureValues.push_back(flowValue);
  if (_pressureValues.size() > _pressureHistoryLengthForPID) {
    _pressureValues.pop_front();
  }
}

void Data::saveBatteryPercentage(unsigned int batteryPercentage) {
  _batteryPercentage = batteryPercentage;
}

void Data::saveOxygenPressureReading(unsigned int pressureValue) {
  // TODO
}

void Data::resetPiData() {
  _flowSum = 0.0;
  _pressureSum = 0;
  _numFlowMeasurements = 0;
  _numPressureMeasurements = 0;
  _numFlowErros = 0;
  _numPressureErrors = 0;
  _batteryPercentage = 0;
  return;
}