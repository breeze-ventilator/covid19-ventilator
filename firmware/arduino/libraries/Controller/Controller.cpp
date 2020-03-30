#include "Controller.h"
#include "OxygenValveStepper.h"
#include "AirIntakeServo.h"
#include "BlowerFanServo.h"

Controller::Controller() {
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
    blowerPID();
}

void Controller::stopArduinoAlarm() {
  alarm.stopAlarm();
}

void Controller::startArduinoAlarm() {
  alarm.keepAlarmRunningForever();
}

void Controller::inhilationControl(Data *data, struct Parameters currentParams) {
 oxygenControl(struct Data *data, struct Parameters currentParams) {
  // modify steps on stepper motor to get desired flow rate (which then gives concentration)
}

void controlOutputsIfAvailable() {
  if (isTimeToControlBlower()){
    controlBlower();
  }
  if (isTimeToControlOxygen()){
    controlOxygen();
  }
  if (isTimeToControlAir()){
    controlAir();
  }
}
