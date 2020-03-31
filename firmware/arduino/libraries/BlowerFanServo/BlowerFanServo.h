#ifndef BLOWER_FAN_SERVO_H
#define BLOWER_FAN_SERVO_H

class BlowerFanServo {
    public:
        BlowerFanServo(int pin);
        void begin();
        void turnOff();
        void writeBlowerPower(double blowerPower);
        Servo _blowerFan;
};

#endif