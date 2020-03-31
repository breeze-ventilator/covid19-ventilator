
/*
  Checks if Serial is available and initializes Raspberry Pi Communication
  
  @params:
  int maxWaitTime - Amount of time to wait for pi to start (milliseconds).

  TODO: Arduino is the first to talk, and the Pi responds

*/
#include "PiCommunication.h"

PiCommunication::PiCommunication(int baudRate) {
  _baudRate = baudRate;
}

PiCommunication::initCommunication(int maxSerialWaitTime, int maxPiWaitTime, int pingInterval) {
  Serial.begin(_baudRate);
  
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

PiCommunication::sendServosNotConnectedErrorToPi() {
  // timeout error
}


/*
  Parses the 11 characters recieved by the Pi.
  
  Note: getPiString() drops the '\n' char at the end
*/
// void parsePiString(){

  
/*
  Helper function to verify checksum from first character of string.
*/
int PiCommunication::isChecksumValid(String piString) {
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