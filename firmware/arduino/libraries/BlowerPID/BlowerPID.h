#ifndef BLOWERPID_H
#define BLOWERPID_H

#define BLOWER_KI 0.0
#define BLOWER_KP 0.5
#define BLOWER_KD 0.1
#define PID_TIME 100

class BlowerPID
    private:
        PID _blowerControl;
        BlowerFanServo _blowerFan;
        double _actualPressure;
        double _blowerPower;
        double _pressureSetPoint;
#endif