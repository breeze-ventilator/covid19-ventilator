#include "pid.h"

// TODO: May be able to replace this code using:   // https://playground.arduino.cc/Code/PIDLibrary/
// int updatePID(){

//   int pSuccess = updateP();
//   int iSuccess = updateI();
//   int dSuccess = updateD();

//   return (pSuccess && iSuccess && dSuccess); 
// }
// int updateP(){
//   return 1;
// }
// int updateI(){
//   return 1;
// }
// int updateD(){
//   return 1;
// }
  

BlowerPID::BlowerPID(Servo blowerFan, double actualPressure, double pressureSetPoint, double blowerPower) {
	: _blowerControl(&actualPressure, &blowerPower, &pressureSetPoint, DIRECT); // PID
	_actualPressure = actualPressure;
	_pressureSetPoint = pressureSetPoint;
	_blowerPower = blowerPower;
	_blowerFan = blowerFan;

	_blowerControl.SetSampleTime(PID_TIME);
  _blowerControl.SetMode(AUTOMATIC);
}

void BlowerPID::control(int setPressure){
	_pressureSetPoint = setPressure;
  if (_blowerControl.control()) {
		_blowerFan.write(map(_blowerPower, 0, 256, 0, 180));
  }
}
