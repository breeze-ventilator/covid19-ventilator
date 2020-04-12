
/*
  Checks if Serial is available and initializes Raspberry Pi Communication

*/
#include "PiCommunication.h"

PiCommunication::PiCommunication(int baudRate, int timeBetweenPiSending) {
  _baudRate = baudRate;
  _lastSentDataTime = millis();
  _timeBetweenPiSending = timeBetweenPiSending;
}

int PiCommunication::initCommunication(int pingInterval) {
  Serial.begin(_baudRate);
  
  int count = 0;
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
    delay(1);
    if (count > MAX_SERIAL_WAIT_TIME) {
      return SERIAL_TIMEOUT_ERROR;
    }
    count++;
  }

  // Arduino sends message to pi until it gets a response
  while (Serial.available() <= 0) { // Serial.available says how many bytes available to read
    // Will send bytes
    Serial.write(WELCOME_MESSAGE);
    delay(pingInterval);
  }

  delay(50);
  String response = Serial.readStringUntil('\n');
  
  if (response.equals("elbowbump")) {
    return NO_ERROR;
  }
  else {
    return PI_SENT_WRONG_RESPONSE_ERROR;
  }
}

int PiCommunication::isTimeToSendDataToPi() {
  return isTime(_lastSentDataTime, _timeBetweenPiSending);
}

int PiCommunication::isPiSendingUsNewParameters() {
  if (Serial.available() == PARAMETER_BYTE_LENGTH + 1) { //  // +1 for first descriptive character
    // read the whole thing and check first character
    char firstByte = Serial.read();
    if (firstByte == 'P') {
      return 1;
    }
  }
  return 0;
}

int PiCommunication::isPiTellingUsThatItsAwake() {
  if (Serial.available() == 1) {
    // Read and check first character
    char firstByte = Serial.read();
    if (firstByte == 'G') {
      return 1;
    }
  }
  return 0;
}

void PiCommunication::getParametersFromPi() {
  Serial.readBytes(parametersBuffer, PARAMETER_BYTE_LENGTH);
  tellPiThatWeGotParameters();
}

void PiCommunication::tellPiThatWeGotParameters() {
  Serial.print("G");
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
  uint8_t batteryPercentage = 1;//(uint8_t) data.batteryPercentage;
  uint8_t breathCompleted = 2;//(uint8_t) state.breathCompleted;
  uint8_t tidalVolume = 3;//;
  // if (breathCompleted) {
  //   tidalVolume = (uint8_t) round(LITERS_TO_TENTH_OF_A_LITER*data.tidalVolume); // 10th of a L/min
  // } else {
  //   tidalVolume = 0;
  // }

  uint8_t abnormalPressure = 0; // TODO: get it
  uint8_t abnormalFiO2 = 0; // TODO: data.fiO2
  
  uint8_t errorCode = NO_ERROR; // TODO: actual error maybe state.error?
  
  Serial.write(checkSum);
  Serial.write(batteryPercentage);
  Serial.write(breathCompleted);
  Serial.write(tidalVolume);
  Serial.write(errorCode);
  Serial.write(abnormalPressure);
  Serial.write(abnormalFiO2);

  _lastSentDataTime = millis();
}

// int PiCommunication::doesMessageContainNewParameters(String receivedString) {
//   if (receivedString.charAt(0) == 'P') {
//     return 1;
//   }
//   else {
//     return 0;
//   }
// }

// int PiCommunication::doesMessageTellUsThatPiIsAwake(String receivedString) {
//   if (receivedString.charAt(0) == 'G') {
//     return 1;
//   }
//   else {
//     return 0;
//   }
// }

// if (curentParams.mode == PRESSURE_SUPPORT_MODE && state.isStartingNewBreath) {
//     // we will re-set system time every breath cycle is complete and when
//     // this happens we will let the pi know so that it can check breaths per minut
//     piCommunications.finishedBreath(&data);
//   }

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