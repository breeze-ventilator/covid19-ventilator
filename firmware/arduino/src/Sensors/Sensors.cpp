#include "Sensors.h"

Sensors::Sensors(int flowReadingFrequency,
                 int mainPressureReadingFrequency,
                 int oxygenReadingFrequency,
                 int batteryVoltageReadingFrequency)
    : flowSensor(FLOW_IC2_ADDRESS, FLOW_OFFSET, FLOW_SCALE),
    mainPressureSensor(MAIN_PRESSURE_PIN)
    // oxygenSensor(OXYGEN_SENSOR_PIN),
    // batteryVoltageSensor(BATTERY_VOLTAGE_PIN)
  {
  _timeBetweenFlowReadings = 1.0/flowReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenMainPressureReadings = 1.0/mainPressureReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenOxygenReadings = 1.0/oxygenReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenBatteryPercentageReadings = 1.0/batteryVoltageReadingFrequency * SECONDS_TO_MILLISECONDS;
  _timeBetweenPrints = 20;

  _lastFlowReadTime = 0;
  _lastMainPressureReadTime = 0;
  _lastOxygenReadTime = 0;
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

    float delta_time = (float)(millis() - _lastFlowReadTime);
    delta_time /= MINUTES_TO_MILLISECONDS;
    data.saveFlowReading(flowValue);

    if (state.breathingStage == INHALATION_STAGE) {
      data.updateTidalVolume(flowValue, delta_time);
    }
    // Serial.println(flowValue);
    _lastFlowReadTime = millis();
  }
  // if (isTimeToReadOxygen()) {
  //   float oxygenReading = oxygenSensor.read();
  //   data.saveOxygenReading(oxygenReading);
  //   _lastOxygenReadTime = millis();
  // }
  if (isTimeToReadMainPressure()) {
    float pressureValue = mainPressureSensor.read(); // analog read (difference between this pressure and atmospheric pressure)
    data.saveMainPressureReading(pressureValue);
    _lastMainPressureReadTime = millis();
    // Serial.println(data.getMainPressureAverageForPID());
    if (isTimeToPrint()) {
      Serial.println(pressureValue);
      // Serial.println(data.getMainPressureAverageForPID());
      _lastPrintTime = millis();
    }
  }
  // if (isTimeToReadBatteryPercentage()) {
  //   unsigned int batteryPercentage = batteryVoltageSensor.readPercentage();
  //   data.saveBatteryPercentage(batteryPercentage);
  //   // Serial.println(batteryPercentage);
  //   _lastBatteryPercentageReadTime = millis();
  // }
}

int Sensors::isTimeToReadFlow() {
  return isTime(_lastFlowReadTime, _timeBetweenFlowReadings);
}
int Sensors::isTimeToReadMainPressure() {
  return isTime(_lastMainPressureReadTime, _timeBetweenMainPressureReadings);
}
int Sensors::isTimeToReadOxygen() {
  return isTime(_lastOxygenReadTime, _timeBetweenOxygenReadings);
}
int Sensors::isTimeToReadBatteryPercentage() {
  return isTime(_lastBatteryPercentageReadTime, _timeBetweenBatteryPercentageReadings);
}
int Sensors::isTimeToPrint() {
  return isTime(_lastPrintTime, _timeBetweenPrints);
}