
/*
  Checks if Serial is available and initializes Raspberry Pi Communication
  
  @params:
  int maxWaitTime - Amount of time to wait for pi to start (milliseconds).

  TODO: Arduino is the first to talk, and the Pi responds

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
  Packaged and send our data to Pi, and reset the storage stuff, put in comms.c
*/
void sendData(pressureAvg, flowAvg){

  // Compile string + data?

  // Transmit all the stuff we need
  //// Can we have multiple lines of data
  
  // Confirm transmit success

  // Reset blocking flags
  blockingFlowReadings = 0;
  blockingPresReadings = 0;
  
  return; 
}


 Function to parse string from Pi, put in comms.c
 */
void parsePiString(String piString){

  // verify checksum
  checksumVal = piString[0];

  // get number of Params
  paramNumber = piString[1];

  // Based on length, how get params
  for (int i = 0; i < paramNumber; i++){
    char identity[2]
    // want to read first two chars
    identity[0] = ;
    identity[1] = ; 

    // want the new value

    // find the relevant struct param
    // will likely be best to use a case-structure

    // update the relevant struct param



  }

  return;
}