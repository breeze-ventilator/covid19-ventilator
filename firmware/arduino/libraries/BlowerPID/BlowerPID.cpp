#include "BlowerPID.h"

#define BLOWER_FAN_SERVO_PIN 9

BlowerPID::BlowerPID(double kP, double kD) {
	_actualPressure = 0;
	_blowerPower = 0;
	_pressureSetPoint = 0;

	: _blowerFanServo(BLOWER_FAN_SERVO_PIN),
		_blowerControl(&_actualPressure, &_blowerPower, &_pressureSetPoint, kP , 0, kD, DIRECT); // PID
	
	_blowerControl.SetSampleTime(PID_TIME);
  _blowerControl.SetMode(AUTOMATIC);
}

void BlowerPID::control(int setPressure, int actualPressure){
	_pressureSetPoint = setPressure;
	_actualPressure = actualPressure;
  if (_blowerControl.control()) {
		_blowerFanServo.writeBlowerPower(_blowerPower);
  }
	return;
}