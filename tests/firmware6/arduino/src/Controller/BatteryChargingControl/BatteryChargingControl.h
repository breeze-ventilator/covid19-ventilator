#ifndef BATTERY_CHARGING_CONTROL_H
#define BATTERY_CHARGING_CONTROL_H

#define BATTERY_SENSE_PIN 6
#define BATTERY_CONTROL_PIN 4

#include "Arduino.h"

class BatteryChargingControl {
	public:
		BatteryChargingControl(int sensePin, int controlPin);
		void control(float setCurrent);
		void init();
	private:
		int _sensePin;
		int _controlPin;
		int _gateVolt;
};


#endif 