#ifndef AIR_CONTROL_H
#define AIR_CONTROL_H
#include "Arduino.h"
#include <Servo.h>

class AirControl {
    public:
        AirControl(int pin, int zeroPoint);
        void begin();
        void control(int desiredFiO2);
    private:
        Servo airIntakeServo;
        int _pin;
        int _zeroPoint;
        void setOpening(int percent);
};

#endif