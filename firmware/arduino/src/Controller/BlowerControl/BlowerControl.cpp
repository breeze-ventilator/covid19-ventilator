#include "BlowerControl.h"

BlowerControl::BlowerControl()
	: _blowerFanServo(BLOWER_FAN_SERVO_PIN),
	  _blowerControl(&_actualPressure, &_blowerPower, &_pressureSetPoint, BLOWER_KP , BLOWER_KI, BLOWER_KD, DIRECT) // PID
{
	_lastReadTime = 0;
}

void BlowerControl::begin() {
	_blowerFanServo.begin();
	_blowerControl.SetSampleTime(PID_TIME);
  _blowerControl.SetMode(AUTOMATIC);
	_blowerControl.SetOutputLimits(15, 90);
}

void BlowerControl::control(float setPressure, float actualPressure){
	// if (millis() - _lastReadTime > 5000) {
	// 	_blowerFanServo.writeBlowerPower(90);
	// 	_lastReadTime = millis();
		
	// } else if (millis() - _lastReadTime > 2500) {
	// 	_blowerFanServo.writeBlowerPower(15);
	// }
	// delay(1);

	_pressureSetPoint = setPressure;
	_actualPressure = actualPressure;
  if (_blowerControl.Compute()) {
		_blowerFanServo.writeBlowerPower(_blowerPower);
	}
}