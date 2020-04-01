#include "BlowerPID.h"

BlowerPID::BlowerPID()
	// : 
	// 	_blowerControl(&_actualPressure, &_blowerPower, &_pressureSetPoint, BLOWER_KP , 0, BLOWER_KD, DIRECT) // PID
{
	// _blowerFanServo.attach(9);
	// _blowerControl.SetSampleTime(PID_TIME);
  // _blowerControl.SetMode(AUTOMATIC);
}

void BlowerPID::control(float setPressure, float actualPressure){
	_pressureSetPoint = setPressure;
	_actualPressure = actualPressure;
	_blowerFanServo.write(60);
	delay(3000);
	_blowerFanServo.write(90);
  // 	if (_blowerControl.Compute()) {
	// 	_blowerFanServo.writeBlowerPower(_blowerPower);
	// }
}

void BlowerPID::begin() {
	_blowerFanServo.attach(9);
  _blowerFanServo.write(90);
  delay(4000);
  _blowerFanServo.write(15);
  delay(2000);
}