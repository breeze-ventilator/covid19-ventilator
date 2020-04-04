#ifndef BLOWERPID_H
#define BLOWERPID_H

#define BLOWER_KI 0.0
#define BLOWER_KP 10
#define BLOWER_KD 1
#define PID_TIME 100
#define BLOWER_FAN_SERVO_PIN 9
#define PID_TIME 100

#include "Arduino.h"
#include <PID_v1.h>
#include <Servo.h>

class BlowerPID : public Servo {
    public:
        BlowerPID();
        void control(float setPressure, float actualPressure);
        void begin();
    private:
        // PID _blowerControl;
        double _actualPressure = 0;
	    double _blowerPower = 0;
	    double _pressureSetPoint = 0;
};
#endif