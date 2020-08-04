#ifndef BLOWER_CONTROL_H
#define BLOWER_CONTROL_H

// Tuned using the Ziegler–Nichols method
#define BLOWER_KP 16.0
#define BLOWER_KI 0.0
#define BLOWER_KD 1.33

#define BLOWER_FAN_SERVO_PIN 9
#define BLOWER_PID_TIME 20

#include "Arduino.h"
#include <PID_v1.h>
#include "BlowerFanServo/BlowerFanServo.h"

class BlowerControl {
    public:
        BlowerControl();
        void control(float setPressure, float actualPressure);
        void begin();
        void blowFan(int blowerPower);
        void beQuiet();
    private:
        PID _blowerControl;
        BlowerFanServo _blowerFanServo;
        double _actualPressure = 0;
	    double _blowerPower = 0;
	    double _pressureSetPoint = 0;
        unsigned long _lastReadTime;
};
#endif