#include "Sensors.h"
#include "OxygenValveStepper.h"
#include "AirIntakeServo.h"
#include "BlowerFanServo.h"

Sensors::Sensors() {
  : oxygenValveStepper(OXYGEN_VALVE_MOTOR_INTERFACE_TYPE,
                       OXYGEN_VALVE_PIN0,
                       OXYGEN_VALVE_PIN1,
                       OXYGEN_VALVE_PIN2,
                       OXYGEN_VALVE_PIN2,
                       OXYGEN_VALVE_LIMIT_SWITCH_PIN,
                       OXYGEN_VALVE_MAX_STEPPER_SPEED,
                       OXYGEN_VALVE_STEPPER_ACCELERATION,
                       OXYGEN_VALVE_ENABLE1_PIN,
                       OXYGEN_VALVE_ENABLE2_PIN),
    alarm(ALARM_PIN),
    airIntake(AIR_INTAKE_PIN),
    blowerFan(BLOWER_FAN_PIN);

}

void Sensors::readSensorsIfAvailableAndSaveSensorData(struct SensorData *data) {
  // take sensor readings
  if (isTimeToReadFlow()) {
    float flowValue = getFlowReading();
    saveFlowReading(flowValue, &data);
  }
  if (isTimeToReadOxygenPressure()) {
    unsigned int pressureValue = getOxygenPressureReading(); // analog read (difference between this pressure and atmospheric pressure)
    saveOxygenPressureReading(pressureValue, &data);
  }
  if (isTimeToReadMainPressure()) {
    unsigned int pressureValue = getMainPressureReading(); // analog read (difference between this pressure and atmospheric pressure)
    saveMainPressureReading(pressureValue, &data);
  }
  if (isTimeToReadBatteryVoltage()) {
    unsigned int batteryVoltage = getBatteryVoltage();
    saveBatteryVoltage(batteryVoltage, &data);
  }
  if (isTimeToReadFan()){
    
  }
}
