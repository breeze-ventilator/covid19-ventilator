#ifndef BLOWERPID_H
#define BLOWERPID_H

#define BLOWER_KI 0.0
#define BLOWER_KP 10
#define BLOWER_KD 1
#define PID_TIME 100
#define BLOWER_FAN_SERVO_PIN 9
#define PID_TIME 100

class BlowerPID {
    public:
        BlowerPID(double kP, double kD);
        void control(float setPressure, float actualPressure);
    private:
        PID _blowerControl;
        BlowerFanServo _blowerFan;
        double _actualPressure; // should check if need pointer
        double _blowerPower;
        double _pressureSetPoint;
};
#endif