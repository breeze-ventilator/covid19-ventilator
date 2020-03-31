#include "Controller.h"
#include "OxygenValveStepper.h"
#include "AirIntakeServo.h"
#include "BlowerFanServo.h"

Controller::Controller(int timeBetweenOxygenControls,
                       int timeBetweenAirControls, double kP, double kD) {
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
    airIntakeServo(AIR_INTAKE_PIN),
    blowerFanServo(BLOWER_FAN_PIN),
    blowerPID(kP, kD);
  _timeBetweenOxygenControls = timeBetweenOxygenControls;
  _timeBetweenAirControls = timeBetweenAirControls;
  _lastOxygenControlTime = 0;
  _lastAirControlTime = 0;
}

int Controller::init() {
  int error = oxygenValveStepper.moveOxygenStepperToZeroPosition();
  return error;
}

void Controller::stopArduinoAlarm() {
  alarm.stopAlarm();
}

void Controller::ringAlarmForever() {
  alarm.keepAlarmRunningForever();
}

void Controller::inhilationControl(Data *data, Parameters *parameters, State *state) {
  
  oxygenControl(&data, &parameters, &state);
  airControl(&parameters);
  // modify steps on stepper motor to get desired flow rate (which then gives concentration)
}

void Controller::exhalationControl(Data *data, Parameters *parameters, State *state) {
  if (isTimeToControlOxygen()) {
    oxygenControl(&data, &parameters, &state);
    _lastOxygenControlTime = millis();
  }
  if (isTimeToControlAir()) {
   airControl(&parameters);
   _lastAirControlTime = millis();
  }
  // modify steps on stepper motor to get desired flow rate (which then gives concentration)
}

void Controller::oxygenControl(Data *data, Parameters *parameters, State *state){
  if (state.isStartingNewBreath) {
    float flow = data.flowInegral / (parameters.currentExpiratoryTime + parameters.currentInspiratoryTime);
    flow *= parameters.currentFiO2 * 1000;

    oxygenValveStepper.stepOxygenFlow( flow, 90); //90 is psi of O2 implement real reading later
          //the other part is the average flow over a breath in l/s
  }
  oxygenValveStepper.runOneStep();
}

int Controller::isTimeToControlOxygen() {
  return isTimeToRead(_lastOxygenControlTime, timeBetweenOxygenControls);
}

int Controller::isTimeToControlAir() {
  return isTimeToRead(_lastAirControlTime, timeBetweenAirControls);
}

int isTimeToRead(unsigned long lastReadTime, int timeBetweenReadings) {
  unsigned long currentTime = millis();
  unsigned long timeDifference = curentTime - _lastFlowReadTime;
  if (timeDifference >= _timeBetweenReadings) {
    return 1;
  }
  else {
    return 0;
  }
}

void Controller::airControl(Parameters *parameters){
  airIntakeServo.setOpening(100 - parameters.currentFiO2);
}

// void controlOutputsIfAvailable() {
//   if (isTimeToControlBlower()){
//     controlBlower();
//   }
//   if (isTimeToControlOxygen()){
//     controlOxygen(&data);
//   }
//   if (isTimeToControlAir()){
//     controlAir();
//   }
// }
