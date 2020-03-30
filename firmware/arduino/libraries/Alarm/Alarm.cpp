#include "Alarm.h"

Alarm::Alarm(int pin) {
  pinMode(pin, OUTPUT);
}

void Alarm::startAlarm() {
	// Simon TODO
}

void Alarm::stopAlarm() {

}

void Alarm::keepAlarmRunningForever() {
  if (!_isAlarmOn) {
    startAlarm();
  }
  runForever();
  
}
void Alarm::runForever() {
  while(1) {
    ;
  }
}

