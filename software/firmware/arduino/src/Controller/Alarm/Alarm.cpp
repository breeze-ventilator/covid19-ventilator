#include "Alarm.h"

Alarm::Alarm(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void Alarm::startAlarm() {
  digitalWrite(_pin, LOW);
  runForever();
}

void Alarm::stopAlarm() {
  digitalWrite(_pin, HIGH);
}

void Alarm::keepAlarmRunningForever() {
  startAlarm();
}

void Alarm::runForever() {
  while(1) {
    ;
  }
}

