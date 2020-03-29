
/*
  Get a flow reading. put in inputs.c?
*/
void getFlowReading(){
  pressureArray[pressureDataCount] = analogRead(FLOW_PIN);
  lastPresReadtime = millis();
  pressureDataCount = (pressureDataCount + 1) % NUM_OF_PRES_MEASUREMENTS; // is this dumb

  // Since we are asynchronously taking pressure and flow measurements  
  // We need to avoid trying to add measurements to indices beyond array length                 
  if (flowDataCount == NUM_OF_FLOW_MEASUREMENTS){ 
    blockingFlowReadings = 1;
  }
  return;
}

/*
  Get a pressure reading. put in inputs.c?
*/
void getPressureReading(){
  flowArray[flowDataCount] = analogRead(PRESSURE_PIN);
  lastFlowReadTime = millis();
  flowDataCount = (flowDataCount + 1) % NUM_OF_FLOW_MEASUREMENTS;

  // Since we are asynchronously taking pressure and flow measurements  
  // We need to avoid trying to add measurements to indices beyond array length
  if (flowDataCount == NUM_OF_FLOW_MEASUREMENTS){
    blockingFlowReadings = 1;
  }
  return;
}
