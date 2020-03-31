#include "Sensors.h"
#include "OxygenPressureSensor.h"
#include "FlowSensor.h"
#include "BatteryVoltageSensor.h"
#include "MainPressureSensor.h"

Sensors::Sensors(int flowReadingFrequency,
                 int mainPressureReadingFrequency,
                 int oxygenPressureReadingFrequency,
                 int batteryVoltageReadingFrequency) {
  : flowSensor(FLOW_IC2_ADDRESS, FLOW_OFFSET, FLOW_SCALE),
    mainPressureSensor(),
    oxygenPressureSensor(OXYGEN_PRESSURE_SENSOR_PIN);
    batteryVoltageSensor(BATTERY_VOLTAGE_PIN);
  _timeBetweenFlowReadings = 1/flowReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenMainPressureReadings = 1/mainPressureReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenOxygenPressureReadings = 1/oxygenPressureReadingFrequency * SECONDS_TO_MILLISECONDS;

  _lastFlowReadTime = 0;
  _lastMainPressureReadTime = 0;
  _lastOxygenPressureReadTime = 0;
  _batteryVoltageReadTime = 0;
}

void Sensors::init() {
  flowSensor.init();
}

void Sensors::readSensorsIfAvailableAndSaveSensorData(Data *data) {
  // take sensor readings
  if (isTimeToReadFlow()) {
    float flowValue = flowSensor.read();
    float delta_time = (millis() - _lastFlowReadTime)/MINUTES_TO_MILLISECONDS;
    data.saveFlowReading(flowValue, delta_time);
    _lastFlowReadTime = millis();
  }
  // if (isTimeToReadOxygenPressure()) {
  //   unsigned int pressureValue = oxygenPressureSensor.read(); // analog read (difference between this pressure and atmospheric pressure)
  //   data.saveOxygenPressureReading(pressureValue);
  //   _lastOxygenPressureReadTime = millis();
  // }
  if (isTimeToReadMainPressure()) {
    unsigned int pressureValue = mainPressureSensor.read(); // analog read (difference between this pressure and atmospheric pressure)
    data.saveMainPressureReading(pressureValue);
    _lastMainPressureReadTime = millis();
  }
  if (isTimeToReadBatteryPercentage()) {
    unsigned int batteryPercentage = batteryVoltageSensor.readPercentage();
    data.saveBatteryPercentage(batteryPercentage);
    _lastBatteryPercentageReadTime = millis();
  }
}

int Sensors::isTimeToReadFlow() {
  return isTimeToRead(_lastFlowReadTime, _timeBetweenFlowReadings);
}
int Sensors::isTimeToReadMainPressure() {
  return isTimeToRead(_lastMainPressureReadTime, _timeBetweenMainPressureReadings);
}
int Sensors::isTimeToReadOxygenPressure() {
  return isTimeToRead(_lastOxygenPressureReadTime, _timeBetweenOxygenPressureReadings);
}
int Sensors::isTimeToReadBatteryPercentage() {
  return isTimeToRead(_lastBatteryPercentageReadTime, _timeBetweenBatteryPercentageReadings);
}

int Sensors::isTimeToRead(unsigned long lastReadTime, int timeBetweenReadings) {
  unsigned long currentTime = millis();
  unsigned long timeDifference = curentTime - _lastFlowReadTime;
  if (timeDifference >= _timeBetweenReadings) {
    return 1;
  }
  else {
    return 0;
  }
}
