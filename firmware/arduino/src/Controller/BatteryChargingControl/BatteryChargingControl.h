#ifndef BATTERY_CHARGING_CONTROL_H
#define BATTERY_CHARGING_CONTROL_H


#include "Arduino.h"



class BatteryChargingControl {
	public:
		BatteryChargingControl(int pin);
		void control(float setCurrent);
		void init();
	private:
		int _sensePin;
		int _controlPin;
		int _gateVolt;
};


#endif