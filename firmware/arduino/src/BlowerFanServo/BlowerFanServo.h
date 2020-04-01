#ifndef BLOWER_FAN_SERVO_H
#define BLOWER_FAN_SERVO_H

#include "Arduino.h"
#include <Servo.h>

class BlowerFanServo {
    public:
        BlowerFanServo(int pin);
        void turnOff();
        void writeBlowerPower(double blowerPower);
        Servo _blowerFan;
};

#endif