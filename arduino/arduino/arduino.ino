/*
 * Hey everyone this is the main code for the ventilator. The ventilator will have the brain here
 *
 * It will get signals from the pi and send signals back to make sure everything is ok at a certain frequency
 * To make sure everything is legit at the begining of the loop we generate an aray  of 0s
 * every critical function will set one of the 0 to a 1 and at the end of the loop we will send it to the pi to show its funcitoning as intended
 *
 * Similarly the pi will send info over and we will read that to see that everything is good
 *
 * The arduino only directly controls the blower and 2 valves plus an alarm (and maybe a relay for power managment)
 *
 * It monitors all sensors (pressure, flow, fan rpm, battery voltage)
 *
 *
 * Every ~ 100ms the arduino will send information over including the I am alive signal
 *          also the sensor readings average over tht time
 *          This will then tell the pi it can send its info over including the I am alive signal
 * 1 = good, 0 = bad
 */
// @TODO include pid.
#include "pi.h"
#include <Servo.h>

unsigned long lastFlowReadTime;
unsigned long lastPresReadTime;
unsigned long currentTime;
bool setup = TRUE;

struct measurements {
  double flow;
  double pressure; 
};

struct parameters {
  bool patientTriggered;
};

/*
  On startup, initializes pins and ensures pi sends message.

  On failure, hangs forever.
*/
void setup() {
  bool initializedPins = initializePins();
  bool piConnected = initializePiCommunication(1000);
  if(initializedPins && piConnected){
    alarmSet(FALSE);
    currentTime = millis();
    lastFlowReadTime = currentTime;
    lastPresReadTime = currentTime;
  }
  else{
    while (true) {}
  }
}

/*

*/
void loop() {
  if(setup){
    // Continously waits for the setup parameters from pi.
    struct parameters params = initializeParametersFromPi();
  }

  //we will re-set system time every breath cycle is complete and when this happens we will let the pi know so that it can check breaths per minute
  struct measurements readings = getAllReadings();

  if inhale{
    inhalation();
  }
  if exhale{
    exhaltion();
  }



  if(patientTriggered){//if in patient triggered mode look for breath attempt
    resetSystemTime();
  }
  //  setPressure(inhalePressure);


    sendAlarm(alarmMessage); //snd the alarm to the pi
    while (systemTime < howLongIWantToWait){
      waitForConfirmation();
    }
    
  if DATACOMPLETE{
    sendData();// send info to the pi including the I am alive data
  }
}


flow_Arry = malloc();

/*
  Gets all sensor readings.
*/
struct measurements getAllReadings(){
  struct measurements values;

  currentTime = millis();
  if( (currentTime - lastPresReadTime) >= PRES_READ_RATE){
    values.pressure = readPressure();
  }

  currentTime = millis();
  if( (currentTime - lastFlowReadTime) >= FLOW_READ_RATE){
    values.flow = readFlow();
  }

  return values;
}


/*
  Runs a breath cycle.
*/
void runBreathCycle(){

}