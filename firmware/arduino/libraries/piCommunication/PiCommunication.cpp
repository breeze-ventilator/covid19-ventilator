
/*
  Checks if Serial is available and initializes Raspberry Pi Communication
  
  @params:
  int maxWaitTime - Amount of time to wait for pi to start (milliseconds).

  TODO: Arduino is the first to talk, and the Pi responds

*/
#include "PiCommunication.h"
#include "Data.h"
#include "State.h"


PiCommunication::PiCommunication(int baudRate) {
  _baudRate = baudRate;
}

int PiCommunication::initCommunication(int maxSerialWaitTime, int maxPiWaitTime, int pingInterval) {
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

int PiCommunication::isDataAvailable() {
  return Serial.available();
}

String PiCommunication::getData() {
  String receivedString = Serial.readStringUntil("\n"); // reads up-to-but-not-including '\n' char
  tellPiThatWeGotData();
  return receivedString;
}

void PiCommunication::tellPiThatWeGotData() {
  Serial.print('G\n');
}

void PiCommunication::sendServosNotConnectedErrorToPi() {
  // timeout error
}

void PiCommunication::sendData(Data *data, State *state) {
  // Send checksum (XOR)
  // Send running average pressure (signed integer)
  // Send running average flow
  // Send “G” for good or “E**” for error and error number
  // Send “\n”
  unsigned char checkSum = 0;
  unsigned char averagePressure = (unsigned char) data.pressureSum / data.numPressureMeasurements;
  unsigned char batteryPercentage = (unsigned char) data.batteryPercentage;
  unsigned char breathCompleted = (unsigned char) state.isStartingNewBreath;
  short flowIntegral;
  if (state.isStartingNewBreath) {
    flowIntegral = (short) floor(LITERS_TO_MILLILITERS*data.flowIntegral); // mL/min
  } else {
    flowIntegral = 0;
  }
  int error = "G"; // TODO: make better
  
  Serial.write(checkSum);
  Serial.write(averagePressure);
  Serial.write(batteryPercentage);
  Serial.write(breathCompleted);
  Serial.write(flowIntegral);
  Serial.write(error);
  Serial.write('/n');
}

// if (curentParams.mode == PRESSURE_SUPPORT_MODE && state.isStartingNewBreath) {
//     // we will re-set system time every breath cycle is complete and when
//     // this happens we will let the pi know so that it can check breaths per minut
//     piCommunications.finishedBreath(&data);
//   }

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