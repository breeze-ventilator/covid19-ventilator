#include "Alarm.h"

Alarm::Alarm(int pinA, int pinB) {
  _pinA = pinA;
  _pinB = pinB;
  pinMode(_pinA, OUTPUT);
  pinMode(_pinB, OUTPUT);
}

void Alarm::startAlarm() {
  digitalWrite(_pinA, LOW);
  digitalWrite(_pinB, LOW);
  runForever(); //this is neclear u cant turn it off...
}

void Alarm::stopAlarm() {
  digitalWrite(_pinA, HIGH);
  digitalWrite(_pinB, HIGH);
}

void Alarm::keepAlarmRunningForever() {
  startAlarm();
}

void Alarm::runForever() {
  while(1) {
    ;
  }
}

