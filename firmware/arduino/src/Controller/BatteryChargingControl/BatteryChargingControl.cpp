#include "BatteryChargingControl.h"

BatteryChargingControl::BatteryChargingControl(int sensePin, int controlPin){
	_sensePin = sensePin;
	_controlPin = controlPin;
	_gateVolt = 0;
}

void BatteryChargingControl::init(){
	pinMode(_controlPin, OUTPUT);
	_gateVolt = 0;
	delay(1);
	for (int i=0; i<500; i++) {
		control();
	}
}

void BatteryChargingControl::control(){
	float current = (float) (analogRead(_sensePin)) * 25.0 / 1024.0; 
	// thoes values are nominal and the zero point (512) might need adjustment

	if (current > BATTERY_SET_CURRENT)
	{ // too much current up gate voltage

			_gateVolt++;
	}
	else if (current < BATTERY_SET_CURRENT)
	{ // too little current lets let more in
			_gateVolt--;
	}

	_gateVolt = constrain(_gateVolt, 0, 255);// makesure we dont go crazy
	// Serial.println(current);
	analogWrite(_controlPin, _gateVolt);
}