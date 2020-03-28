#ifndef INIT_H
#define INIT_H

//=========== Global PARAMS  ===============//
// Define reading rates (ms?)
#define FLOW_READ_RATE 100
#define PRES_READ_RATE 50

// https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/

// Input pin numbers
#define PRESSURE_PIN A1
#define FLOW_PIN A2
#define BATT_PIN A3
#define FAN_SENS_PIN A4
#define STEP_MOTOR_ZERO_PIN A5


// Output pin 
#define BLOWER_PIN D5 //is pwm (servo)
#define ALARM_PIN D6  
#define AIR_CONT_PIN D7 //is pwm (servo)
//O2 servo so needs 4 pins?
#define O2_CONT_PIN0 A6
#define O2_CONT_PIN1 A7
#define O2_CONT_PIN2 A8
#define O2_CONT_PIN3 A9


#endif