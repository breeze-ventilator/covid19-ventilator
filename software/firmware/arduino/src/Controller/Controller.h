#ifndef CONTROLLER_H
#define CONTROLLER_H

#define AIR_INTAKE_PIN 8
#define AIR_INTAKE_OFF_PIN 10
#define BLOWER_FAN_PIN 9
#define AIR_INTAKE_ZERO_POINT 110
#define TIME_BETWEEN_AIR_CONTROLS 100 // ms

#include "OxygenControl/OxygenControl.h"
#include "AirControl/AirControl.h"
#include "BlowerControl/BlowerControl.h"
#include "Alarm/Alarm.h"
#include "BatteryChargingControl/BatteryChargingControl.h"

#include "../Data/Data.h"
#include "../Parameters/Parameters.h"
#include "../State/State.h"
#include "../Defs/defs.h"

#include <math.h>

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
        void standby();
        void delayWithCharging(unsigned long delayTime);
        void controlAir(Parameters &parameters);
    private:
        // Alarm alarm;
        OxygenControl oxygenControl;
        AirControl airControl;
        BlowerControl blowerControl;
        BatteryChargingControl batteryChargingControl;
        void controlPressure(float desiredPressure, Data &data);
};

#endif