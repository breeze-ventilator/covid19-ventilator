


/*
  Checks if Serial is available and initializes Raspberry Pi Communication
  
  @params:
    int millies - Amount of time to wait for pi to start.
*/
int initializePiCommunication(int millies) {
    Serial.begin(9600);
    int count = 0;
    while (!Serial.available()){
          count += 5;
          delay(5); 
          if (count > millies) {
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
  
}