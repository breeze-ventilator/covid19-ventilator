#include "BlowerPID.h"

BlowerPID::BlowerPID()
	: _blowerFanServo(BLOWER_FAN_SERVO_PIN),
		_blowerControl(&_actualPressure, &_blowerPower, &_pressureSetPoint, BLOWER_KP , 0, BLOWER_KD, DIRECT) // PID
{
	_blowerControl.SetSampleTime(PID_TIME);
  _blowerControl.SetMode(AUTOMATIC);
}

void BlowerPID::control(float setPressure, float actualPressure){
	_pressureSetPoint = setPressure;
	_actualPressure = actualPressure;
	_blowerFanServo.write(60);
  // 	if (_blowerControl.Compute()) {
	// 	_blowerFanServo.writeBlowerPower(_blowerPower);
	// }
}

void BlowerPID::begin() {
	_blowerFanServo.begin();
}