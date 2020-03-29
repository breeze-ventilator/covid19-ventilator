/*
  Turns on or off the arduino alarm.

  @params:
    bool set - Turn on or off alarm.
*/

int turnOffAlarm(){
  // Turn Off Alarm
  return;
}

void keepAlarmRunningForever() {
  while(1) {}
  return;
}
/*

// TODO: May be able to replace this code using:   // https://playground.arduino.cc/Code/PIDLibrary/
int updatePID(){

  int pSuccess = updateP();
  int iSuccess = updateI();
  int dSuccess = updateD();

  return (pSuccess && iSuccess && dSuccess); 
}
int updateP(){
  return 1;
}
int updateI(){
  return 1;
}
int updateD(){
  return 1;
}

*/

/*
  Update our parameters based on the parsed Pi message.
*/
int setParam(String id, int value){
  
  // TODO: BROKEN FOR MODE PARAMETER, since mode is a string within the struct
  // TODO: this may be an inappropriate file for this

  switch (id) {
    case "MM":
      // mode
      parameters.mode = value;
      return 1;
    case "IT":
      // exhalation time
      parameters.expiratoryTime = value;
      return 1;
    case "TT":
      // TODO: questionable, based on the protocol sheet
      // tidal volume
      parameters.tidalVolumeGoal = value;
      return 1;
    case "FF":
      //FiO2
      parameters.fiO2 = value;
      return 1;
    case "IT":
      // inspiration time
      parameters.inspiratoryTime = value;
      return 1;
    case "EP":
      // PEEP (exhalation pressure)
      parameters.peakExpiratoryPressure = value = value;
      return 1;
    case "IP":
      // Inhalation Pressure
      parameters.peakInspiratoryPressure = value;
      return 1;
    case "PH":
      // High Pressure alarm setting
      parameters.highPressureBound = value;
      return 1;
    case "PL":
      // Low pressure alarm setting
      parameters.lowPressureBound = value;
      return 1;
    case "VH":
      // high(?) minute ventilation alarm settings
      parameters.highMinuteVentilationBound = value;
      return 1;
    case "VL":
      // low(?) minute ventilation alarm settings
      parameterslowMinuteVentilationBound = value;
      return 1;
    default:
      // Something fucked up, re-send the data or raise alarm
      return -1;
  };
}