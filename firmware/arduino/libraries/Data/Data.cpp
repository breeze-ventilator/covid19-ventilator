#include "Data.h"
// #include <list>

Data::Data() {
}

void Data::saveFlowReading(float flowValue, float delta_time) {
  flowIntegral += flowValue*delta_time;
}

void Data::saveMainPressureReading(unsigned int pressureValue) {
  // TODO change back to list
  // pressureValues.push_back(pressureValue);
  // if (pressureValues.size() > PRESSURE_HISTORY_LENGTH_FOR_PID) {
  //   pressureValues.pop_front();
  // }
  pressureValues = pressureValue;
  pressureSum += pressureValue;
  numPressureMeasurements += 1;
}

float Data::getMainPressureAverageForPID() {
  return (float) pressureValues;
  // float average = 0;
  // for (float i=0; i<pressureValues.size(); i++) {
  //   average += pressureValues;
  // }
  // average /= pressureValues.size();
  // return average;
}

void Data::saveBatteryPercentage(unsigned int newBatteryPercentage) {
  batteryPercentage = newBatteryPercentage;
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