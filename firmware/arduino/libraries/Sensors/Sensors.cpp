#include "Sensors.h"
#include "OxygenValveStepper.h"
#include "AirIntakeServo.h"
#include "BlowerFanServo.h"

#define SECONDS_TO_MILLISECONDS 1000

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
    data.saveFlowReading(flowValue);
  }
  if (isTimeToReadOxygenPressure()) {
    unsigned int pressureValue = oxygenPressureSensor.read(); // analog read (difference between this pressure and atmospheric pressure)
    data.saveOxygenPressureReading(pressureValue);
  }
  if (isTimeToReadMainPressure()) {
    unsigned int pressureValue = mainPressureSensor.read(); // analog read (difference between this pressure and atmospheric pressure)
    data.saveMainPressureReading(pressureValue);
  }
  if (isTimeToReadBatteryPercentage()) {
    unsigned int batteryPercentage = getBatteryPercentage();
    data.saveBatteryPercentage(batteryPercentage);
  }
}

int isTimeToReadFlow() {
  return isTimeToRead(_lastFlowReadTime, _timeBetweenFlowReadings);
}
int isTimeToReadMainPressure() {
  return isTimeToRead(_lastMainPressureReadTime, _timeBetweenMainPressureReadings);
}
int isTimeToReadOxygenPressure() {
  return isTimeToRead(_lastOxygenPressureReadTime, _timeBetweenOxygenPressureReadings);
}
int isTimeToReadBatteryPercentage() {
  return isTimeToRead(_lastBatteryPercentageReadTime, _timeBetweenBatteryPercentageReadings);
}

int isTimeToRead(unsigned long lastReadTime, int timeBetweenFlowReadings) {
  unsigned long currentTime = millis();
  unsigned long timeDifference = curentTime - _lastFlowReadTime;
  if (timeDifference >= _timeBetweenReadings) {
    return 1;
  }
  else {
    return 0;
  }
}
