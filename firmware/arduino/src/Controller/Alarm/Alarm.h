#ifndef ALARM_H
#define ALARM_H
#include "Arduino.h"
class Alarm {
    public:
        Alarm(int pin);
        void startAlarm();
        void stopAlarm();
        void keepAlarmRunningForever();
    private:
        int _pin;
        void runForever();
};

#endif