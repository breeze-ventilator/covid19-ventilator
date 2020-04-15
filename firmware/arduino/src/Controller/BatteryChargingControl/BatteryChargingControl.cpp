#include "BatteryChargingControl.h"

BatteryChargingControl::BatteryChargingControl(int pin){
    _pin = pin;

}

void BatteryChargingControl::init(){
    pinMode(_pin, OUTPUT);
}


void BatteryChargingControl::control(float setCurrent){
    float current = (float) (analogRead(_pin) – 512) * 50 / 1024; 
    //thoes values are nominal and the zero point (512) might need adjustment

    if (current > setCurrent)
    { // too much current up gate voltage

        _gateVolt++;
    }
    else if (current < setCurrent)
    { // too little current lets let more in
        _gateVolt--;
    }

    //this is right way to do it but small problem in elecctronics prevents it

    // //state machine of transitions and feedback loop!
    // if (current >= 0 && _isOnBattery == true)
    // { //we just got plugged in!
    //     _gateVolt = 255; //turn off the mosfet
    //     _isOnBattery = false; //we are now charging!!
    // } else if (current < 0 && _isOnBattery == true)
    // {// we are on battery keep mosfet wide open
    //     _gateVolt = 0;
    // } else if (current >=0 && _isOnBattery == false)
    // {//we are cahrging
    //     if (current > setCurrent)
    //     { // too much current up gate voltage

    //         _gateVolt++;

    //     }else if (current < setCurrent)
    //     { // too little current lets let more in
    //         _gateVolt--;
    //     }
        
    // } else if(current <= 0 && _isOnBattery == false)
    // {//we just got unplugged!!!!
    //     //flood the gate open
    //     _gateVolt = 0;
    //     _isOnBattery = true;
    // }


    _gateVolt = constrain(_gateVolt, 0, 255);// makesure we dont go crazy

    analogWrite(_pin, _gateVolt);

    return;
}