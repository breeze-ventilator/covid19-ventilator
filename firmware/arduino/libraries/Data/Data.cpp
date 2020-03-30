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

void Sensors::saveOxygenPressureReading(unsigned int pressureValue) {
  _pressureValues.push_back(flowValue);
  if (_pressureValues.size() > _pressureHistoryLengthForPID) {
    _pressureValues.pop_front();
  }
}