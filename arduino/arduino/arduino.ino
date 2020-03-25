/*
 * Hey everyone this is the main code for the ventilator. The ventilator will have the brain here
 * 
 * It will get signals from the pi and send signals back to make sure everything is ok at a certain frequency
 * To make sure everything is legit at the begining of the loop we generate an aray  of 0s
 * every critical function will set one of the 0 to a 1 and at the end of the loop we will send it to the pi to show its funcitoning as intended
 * 
 * similarly the pi will send info over and we will read that to see that everything is good
 * 
 * The arduino only directly controls the blower and 2 valves plus an alarm (and maybe a relay for power managment)
 * 
 * it monitors all sensors (pressure, flow, fan rpm, battery voltage)
 * 
 * 
 * Every ~ 100ms the arduino will send information over including the I am alive signal
 *          also the sensor readings average over tht time
 *          This will then tell the pi it can send its info over including the I am alaive signal
 *  
 * 
 * 
 * 
 * 
 * 
 * 
 */





void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


  //get System time! everything happens depending on the system time in cycles
  //we will re-set system time every breath cycle is complete and when this happens we will let the pi know so that it can check breaths per minute

  


  getAllreadings(); // pick up all readings we can

  if(patienttriggered){//if in patient triggered mode look for breath attempt
    resetSystemTime();
    setPressure(inhalePressure);
  }

  if(systemtime){ //if we got to a point in the breath cycle that we need to inhale
    setPressure(inhalePressure);
  } else if (systemTime){ // if we are at peep stage
    setPressure(exhalePressure);// we might need some adjustments for these since the pressures arent exactly ideal and a correcction might be needed
  }

  blowerControl();// adjust the power given to the blower to reach desired pressure

  oxygenControl();// adjust needle valve and air restriciton to get desired O2

  if(checkLimits()){ // are we in a normal state? should we start an alarm?
    sendAlarm(alarmMessage); //snd the alarm to the pi
    while (systemTime < howLongIWantToWait){
      waitForConfirmation();
    }
    if (noConfirmation){
      alarm();
    }

  }
  
  sendData();// send info to the pi including the I am alive data
  //probably should be done 10 times a second and nt more often but 
  //read instrucctions from serial and adjust if needed, reamins to be seen how to handle changes during a breath. probably makes sens to wait for next breath but could be dangerous
  //the pi should only speak when spoken to. The arduino initiates communication 
 
}
