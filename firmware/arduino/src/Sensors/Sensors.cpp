#include "Sensors.h"

Sensors::Sensors(int flowReadingFrequency,
                 int mainPressureReadingFrequency,
                 int oxygenPressureReadingFrequency,
                 int batteryVoltageReadingFrequency)
    : flowSensor(FLOW_IC2_ADDRESS, FLOW_OFFSET, FLOW_SCALE),
    mainPressureSensor(),
    // oxygenPressureSensor(OXYGEN_PRESSURE_SENSOR_PIN),
    batteryVoltageSensor(BATTERY_VOLTAGE_PIN)
  {
  _timeBetweenFlowReadings = 1.0/flowReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenMainPressureReadings = 1.0/mainPressureReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenOxygenPressureReadings = 1.0/oxygenPressureReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenBatteryPercentageReadings = 1.0/batteryVoltageReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenPrints = 100;

  _lastFlowReadTime = 0;
  _lastMainPressureReadTime = 0;
  _lastOxygenPressureReadTime = 0;
  _lastBatteryPercentageReadTime = 0;
  _lastPrintTime = 0;
}

void Sensors::init() {
  flowSensor.init();
}

void Sensors::readSensorsIfAvailableAndSaveSensorData(Data &data, State &state) {
  // take sensor readings
  if (isTimeToReadFlow()) {
    int error = 0;
    // flow read in L/min
    float flowValue = flowSensor.read(&error); // we're not doing anything with this error yet
    if (flowValue > 250) { // max range
      flowValue = 0;
    }

    // flow in L/min
    // tidal volume in L
    // flow (L/min) * (min/ms) * ∆t (ms)

    float delta_time = (float)(millis() - _lastFlowReadTime);
    delta_time /= MINUTES_TO_MILLISECONDS;
    data.saveFlowReading(flowValue);
    if (state.breathingStage == INHALATION_STAGE) {
      data.updateTidalVolume(flowValue, delta_time);
    }
    // Serial.println(flowValue);
    _lastFlowReadTime = millis();
  }
  // if (isTimeToReadOxygenPressure()) {
  //   unsigned int pressureValue = oxygenPressureSensor.read(); // analog read (difference between this pressure and atmospheric pressure)
  //   data.saveOxygenPressureReading(pressureValue);
  //   _lastOxygenPressureReadTime = millis();
  // }
  if (isTimeToReadMainPressure()) {
    float pressureValue = mainPressureSensor.read(); // analog read (difference between this pressure and atmospheric pressure)
    if (pressureValue < 1000) {
      data.saveMainPressureReading(pressureValue);
      // Serial.println(data.getMainPressureAverageForPID());
      // if (isTimeToRead(_lastPrintTime, _timeBetweenPrints)) {
        // Serial.println(data.getMainPressureAverageForPID());
      //   _lastPrintTime = millis();
      // }
      _lastMainPressureReadTime = millis();
    }
  }
  if (isTimeToReadBatteryPercentage()) {
    unsigned int batteryPercentage = batteryVoltageSensor.readPercentage();
    data.saveBatteryPercentage(batteryPercentage);
    // Serial.println(batteryPercentage);
    _lastBatteryPercentageReadTime = millis();
  }
}

int Sensors::isTimeToReadFlow() {
  return isTime(_lastFlowReadTime, _timeBetweenFlowReadings);
}
int Sensors::isTimeToReadMainPressure() {
  return isTime(_lastMainPressureReadTime, _timeBetweenMainPressureReadings);
}
int Sensors::isTimeToReadOxygenPressure() {
  return isTime(_lastOxygenPressureReadTime, _timeBetweenOxygenPressureReadings);
}
int Sensors::isTimeToReadBatteryPercentage() {
  return isTime(_lastBatteryPercentageReadTime, _timeBetweenBatteryPercentageReadings);
}
