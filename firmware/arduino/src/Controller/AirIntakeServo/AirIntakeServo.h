#ifndef AIR_INTAKE_SERVO_H
#define AIR_INTAKE_SERVO_H
#include <Servo.h>
class AirIntakeServo {
    public:
        AirIntakeServo(int pin, int zeroPoint, int offPin);
        void begin();
        void setOpening(int percent);
        void setState(bool state);
    private:
        Servo _airIntake;
        int _pin;
        int _zeroPoint;
        int _offPin;
};

#endif