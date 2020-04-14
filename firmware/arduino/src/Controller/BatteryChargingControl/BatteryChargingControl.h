#ifndef BATTERY_CHARGING_CONTROL_H
#define BATTERY_CHARGING_CONTROL_H


#include "Arduino.h"

class BatteryChargeControl {
	public:
		BatteryChargeControl(int pin);
		bool control(float setCurrent);
		void init();
	private:
		int _pin;
		bool _isOnBattery;
		int _gateVolt;
};


#endif