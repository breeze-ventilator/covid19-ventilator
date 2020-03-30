
/*
  Checks if Serial is available and initializes Raspberry Pi Communication
  
  @params:
  int maxWaitTime - Amount of time to wait for pi to start (milliseconds).

  TODO: Arduino is the first to talk, and the Pi responds

*/
#include "piCommunication.h"
#include "controls.h" // for the param update
#include "utilities.h"


/*
  Handshake/elbowbump with Pi.
  Arduino -> Pi -> Arduino.

  Returns 1 if connected, 0 if not.
*/
int initializePiCommunication(int maxSerialWaitTime, int maxPiWaitTime, int pingInterval) {
  int BAUD_RATE = 9600 // move
  Serial.begin(BAUD_RATE);
  
  int count = 0;
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    count++;
    delay(1);
    if (count > maxSerialWaitTime){
      return TIMEOUT_ERROR;
    }
  }

  // Arduino sends message to pi until it gets a response
  count = 0;
  while (Serial.available() <= 0) { // Serial.available says how many bytes available to read
    Serial.print('elbowbump\n');
    count += pingInterval;
    delay(pingInterval);
    if (count > maxWaitTime) {
      return TIMEOUT_ERROR;
    }
  }
  delay(50);
  String response = Serial.readStringUntil('\n'); // doesn't include '/n'
  if (response.equals('elbowbump')) {
    return 1;
  }
  else {
    return PI_SENT_WRONG_CODE_ERROR;
  }
}


/*
  Gets initial setup parameters from pi.
*/
int setupInitialParametersFromPi() {
    String initialParameterString = getPiString();
    parsePiString(initialParameterString);
    return 1;
}


/*
  Package and send data to Pi, and reset the storage stuff. Error checking is done elsewhere.
*/
void sendData(pressureAvg, flowAvg){

  int data[2] = {pressureAvg, flowAvg};
  int checksum = createCheckSum(data, 2); // TODO: this function must be implemented

  Serial.write('D');
  Serial.write(checksum);
  Serial.write(pressureAvg);
  Serial.write(flowAvg);
  Serial.write(status); // TODO; status must be implemented (either 'G', or an error code)
  Serial.write('\n');

  return; 
}

/*
  Helper function to verify checksum from first character of string.
*/
int isChecksumValid(String piString) {
  int checkSumVal = piString.charAt(0); // ^ XOR
  
  int testVal = byte(piString.charAt(1));
  for (int i = 2; i < piString.length(); i++){
    testVal = testVal ^ byte(piString.charAt(i));
  }

  if (checkSumVal == testVal){
    return 1;
  }
  return 0;
}

/*
  Reads in the parameter string from the Pi, 12 characters long including \n
*/
String getPiString(){
  // Reads until \n, and returns string without '\n'
  String msg = Serial.readStringUntil('\n');
  return msg;
}

/*
  Parses the 11 characters recieved by the Pi.
  
  Note: getPiString() drops the '\n' char at the end
*/
void parsePiString(){
/* 
Position   PARAM
  1       Checksum 
  2       Mode (1, 2, or 3)
  3       Exhalation time (tells us the rate if controlled)
  4       FiO2
  5       Inspiration time
  6       PEEP (exhalation pressure)
  7       Inhalation pressure
  8       High pressure alarm setting
  9       Low pressure alarm settings
  10      High, minute ventilation alarm settings
  11      Low, minute Ventilation alarm settings
*/
  