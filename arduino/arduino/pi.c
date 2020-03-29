
/*
  Checks if Serial is available and initializes Raspberry Pi Communication
  
  @params:
  int maxWaitTime - Amount of time to wait for pi to start (milliseconds).

  TODO: Arduino is the first to talk, and the Pi responds

*/

#include "controls.h" // for the param update
#include "utilities.h"


/*
  Handshake/elbowbump with Pi
*/
int initializePiCommunication(int maxWaitTime) {
  Serial.begin(9600);
  int count = 0;
  while (!Serial.available()){
      count += 5;
      delay(5); 
      if (count > maxWaitTime) {
        return 0;
      }  
  }

  String s1 = Serial.readStringUntil('\n');

  if(s1.equals('elbowbump')){
    // Successful communication
    Serial.write("elbowbump\n");
    return 1;
  }
  else{
    // Error out, received wrong message.
    return 0;
  }

}


/*
  Continously waits For Pi to send over setup parameters.
*/
int initializeParametersFromPi(){
    initialParameterString = getPiString();
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
 Function to parse string from Pi
 */
void parsePiString(String piString){

  // verify checksum
  checksumVal = piString[0];
  if (checksumVal != 0) {
    // RAISE ALARM
  
  }

  // get number of Params
  paramNumber = piString[1];

  // Based on length, now get all of the params
  for (int i = 0; i < paramNumber; i++){
    char identity[2];
    int val; // do we want this to be a double?

    // want to read first two chars
    identity[0] = piString[1+i];
    identity[1] = piString[1+(i+1)];  // weird way to write it, but kinda sorta better readability

    // want the new value
    val = piString[1+(i+2)];

    result = setParam(identity, val);
    if (result == -1){
      // TODO: THROW AN ALARM, the identiTy string didn't match any of the OPTION
    }
  }

  return;
}