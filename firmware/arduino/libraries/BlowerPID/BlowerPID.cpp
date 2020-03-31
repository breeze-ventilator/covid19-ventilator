#include "BlowerPID.h"

BlowerPID::BlowerPID(double kP, double kD) {
	_actualPressure = 0;
	_blowerPower = 0;
	_pressureSetPoint = 0;

	: _blowerFanServo(BLOWER_FAN_SERVO_PIN),
		_blowerControl(&_actualPressure, &_blowerPower, &_pressureSetPoint, BLOWER_KP , 0, BLOWER_KD, DIRECT); // PID
	
	_blowerControl.SetSampleTime(PID_TIME);
  _blowerControl.SetMode(AUTOMATIC);
}

void BlowerPID::control(float setPressure, float actualPressure){
	_pressureSetPoint = setPressure;
	_actualPressure = actualPressure;
  if (_blowerControl.control()) {
		_blowerFanServo.writeBlowerPower(_blowerPower);
  }
}