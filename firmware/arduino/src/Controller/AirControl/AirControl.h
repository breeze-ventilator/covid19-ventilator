#ifndef AIR_CONTROL_H
#define AIR_CONTROL_H

#include "Arduino.h"
#include <Servo.h>

#define AIR_INTAKE_ZERO_POINT 110

class AirControl {
    public:
        AirControl(int pin, int offPin);
        void begin();
        void control(int desiredFiO2);
        void activate();
        void deactivate();
    private:
        Servo airIntakeServo;
        int _pin;
        int _offPin;
        void setOpening(int percent);
};

#endif