#ifndef ALARM_H
#define ALARM_H
#include "Arduino.h"
class Alarm {
    public:
        Alarm(int pinA, int pinB);
        void startAlarm();
        void stopAlarm();
        void keepAlarmRunningForever();
    private:
        int _pinA;
        int _pinB
        void runForever();
};

#endif