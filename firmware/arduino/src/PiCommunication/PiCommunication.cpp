
/*
  Checks if Serial is available and initializes Raspberry Pi Communication

*/
#include "PiCommunication.h"

PiCommunication::PiCommunication(int baudRate, int timeBetweenPiSending) {
  _baudRate = baudRate;
  _lastSentDataTime = millis();
  _timeBetweenPiSending = timeBetweenPiSending;
  _breathCompletedToSend = 0;
  _tidalVolumeToSend = 0;
  _apneaTimeExceededError = NO_ERROR;
}

int PiCommunication::initCommunication(int pingInterval) {
  Serial.begin(_baudRate);
  delay(10);
  
  int count = 0;
  // while (!Serial) {
  //   // wait for serial port to connect. Needed for native USB port only
  //   delay(1);
  //   if (count > MAX_SERIAL_WAIT_TIME) {
  //     return SERIAL_TIMEOUT_ERROR;
  //   }
  //   count++;
  // }

  // Serial.write(3);

  // Arduino sends message to pi until it gets a response
  while (Serial.available() <= 0) { // Serial.available says how many bytes available to read
    // Will send bytes
    Serial.write(WELCOME_MESSAGE);
    delay(pingInterval);
  }

  delay(50);
  uint8_t response = Serial.read();
  
  if (response == WELCOME_MESSAGE) {
    return NO_ERROR;
  }
  else {
    return PI_SENT_WRONG_RESPONSE_ERROR;
  }
}

int PiCommunication::isTimeToSendDataToPi() {
  return isTime(_lastSentDataTime, _timeBetweenPiSending);
}

int PiCommunication::isDataAvailable() {
  if (Serial.available() == MESSAGE_LENGTH_FROM_PI) {
    return 1;
  } else {
    return 0;
  }
}

void PiCommunication::flush() {
  while (Serial.available() > 0) {
    Serial.read();
  }
}

void PiCommunication::updateErrors(State &state) {
  _apneaTimeExceededError = state.apneaTimeExceededError;
}

char PiCommunication::getMessageType() {
  char messageType = (char) Serial.read();
  return messageType;
}


void PiCommunication::getParametersFromPi() {
  Serial.readBytes(parametersBuffer, PARAMETER_BYTE_LENGTH);
  // tellPiThatWeGotParameters();
}

void PiCommunication::updateValuesForPiUponBreathCompleted(Data &data, State &state) {
  _breathCompletedToSend = state.breathCompleted;
  _tidalVolumeToSend = (uint8_t) round(data.tidalVolume * LITERS_TO_TENTH_OF_A_LITER);  // 10th of a L/min
}

void PiCommunication::resetValuesForPi() {
  _breathCompletedToSend = 0;
  _tidalVolumeToSend = 0;
  _apneaTimeExceededError = NO_ERROR;
}

void PiCommunication::sendDataToPi(Data &data, State &state) {
  /*
  What we send:
  - Checksum (XOR) (8 bits)
  - Battery percentage (8 bit unsigned integer)
  - Breath complete (8 bit unsigned integer): 0 or 1
  - Tidal Volume in mL (32 bit unsigned integer). Only use this value if breath complete == 1.
  - Error code (8 bit unsigned integer). If 0, it’s fine.
  - Average pressure
  - O2
  - Send “\n”

  */
  uint8_t checkSum = 0;
  uint8_t batteryPercentage = state.breathingStage;// 10;// parameters.currentMode; //(uint8_t) data.batteryPercentage;
  uint8_t breathCompleted = _breathCompletedToSend;
  uint8_t tidalVolume = _tidalVolumeToSend;

  /*
  Possible Errors:
  - FiO2 is abnormal
  - Peep abnormal
  - Inspiratory pressure abnormal
  */

  uint8_t errorCode = NO_ERROR; // TODO: actual error maybe state.error?
  uint8_t isPressureNormal = NO_ERROR; // TODO: get it
  uint8_t isFiO2Normal = TOO_HIGH; // TODO: data.fiO2
  
  // TO DO: should send apnea time exceeded error
  Serial.write(checkSum);
  Serial.write(batteryPercentage);
  Serial.write(breathCompleted);
  Serial.write(tidalVolume);
  Serial.write(errorCode);
  Serial.write(isPressureNormal);
  Serial.write(isFiO2Normal);

  _lastSentDataTime = millis();
  resetValuesForPi();
}

/*
  Helper function to verify checksum from first character of string.
*/
// int PiCommunication::isChecksumValid(String piString) {
//   int checkSumVal = piString.charAt(0); // ^ XOR

//   int testVal = byte(piString.charAt(1));
//   for (int i = 2; i < piString.length(); i++){
//     testVal = testVal ^ byte(piString.charAt(i));
//   }

//   if (checkSumVal == testVal){
//     return 1;
//   }
//   return 0;
// }