#include "Alarm.h"

Alarm::Alarm(int pin) {
  pinMode(pin, OUTPUT);
}

void Alarm::turnAlarmOn() {
	// Simon TODO
}

void Alarm::turnAlarmOff() {

}

void Alarm::keepAlarmRunningForever() {
  while(1) {
    ;
  }
  return;
}

