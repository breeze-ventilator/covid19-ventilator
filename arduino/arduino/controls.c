/*
  Turns on or off the arduino alarm.

  @params:
    bool set - Turn on or off alarm.
*/
int alarmSet(bool set){
  if (set) {
    // Turn On Alarm
  }
  else if(!set) {
    // Turn Off Alarm
  }
  else {
    return 0;
  }
  return 1;
}