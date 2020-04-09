#include "BlowerPID.h"

BlowerPID::BlowerPID()
	: _blowerFanServo(BLOWER_FAN_SERVO_PIN),
	  _blowerControl(&_actualPressure, &_blowerPower, &_pressureSetPoint, BLOWER_KP , BLOWER_KI, BLOWER_KD, DIRECT) // PID
{
}

void BlowerPID::begin() {
	_blowerFanServo.begin();
	_blowerControl.SetSampleTime(PID_TIME);
  _blowerControl.SetMode(AUTOMATIC);
	_blowerControl.SetOutputLimits(15, 90);
}

void BlowerPID::control(float setPressure, float actualPressure){
	_pressureSetPoint = setPressure;
	_actualPressure = actualPressure;
  if (_blowerControl.Compute()) {
		_blowerFanServo.writeBlowerPower(_blowerPower);
	}
}