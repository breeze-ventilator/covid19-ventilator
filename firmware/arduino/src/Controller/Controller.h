#ifndef CONTROLLER_H
#define CONTROLLER_H

#define AIR_INTAKE_PIN 8
#define BLOWER_FAN_PIN 9
#define AIR_INTAKE_ZERO_POINT 110
#define TIME_BETWEEN_OXYGEN_CONTROLS 1000 // ms
#define TIME_BETWEEN_AIR_CONTROLS 100 // ms

#include "OxygenControl/OxygenControl.h"
#include "AirIntakeServo/AirIntakeServo.h"
#include "BlowerControl/BlowerControl.h"
#include "Alarm/Alarm.h"
#include "BatteryChargingControl/BatteryChargingControl.h"

#include "../Data/Data.h"
#include "../Parameters/Parameters.h"
#include "../State/State.h"
#include "../Defs/defs.h"

class Controller {
    public:
        Controller();
        void init();
        void stopArduinoAlarm();
        void startArduinoAlarm();
        void inhalationControl(Data &data, Parameters &parameters, State &state);
        void exhalationControl(Data &data, Parameters &parameters);
        void blowFan(int blowerPower);
        void manageBattery();
    private:
        // int isTimeToControlOxygen();
        // int isTimeToControlAir();
        // int isTimeToRead(unsigned long lastReadTime, int timeBetweenReadings);

        // OxygenControl oxygenControl;
        // Alarm alarm;
        // AirIntakeServo airIntakeServo;
        void controlPressure(float desiredPressure, Data &data);
        BlowerControl blowerControl;
        unsigned long _lastAirControlTime;
        BatteryChargingControl batteryChargingControl;
};

#endif