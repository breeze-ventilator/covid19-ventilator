#ifndef INIT_H
#define INIT_H

// TODO: Simon are these valid?

//=========== Global PARAMS  ===============//
// Define reading rates (ms)
#define FLOW_READ_RATE 100
#define PRESSURE_READ_RATE 2  // 500 Hz freq => 2 ms period

// Defines size of global storage arrays
#define NUM_OF_PRESSURE_MEASUREMENTS 10 
#define NUM_OF_FLOW_MEASUREMENTS 10 

#define SEND_DATA_TIMEOUT 10

// https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/

// Input pin numbers
#define PRESSURE_PIN 6
#define BATTERY_PIN 7
#define FAN_SENSOR_PIN 40
#define STEP_MOTOR_ZERO_PIN A5

// Output pin 
#define BLOWER_PIN 9 //is pwm (servo)
#define ALARM_PIN 25
#define AIR_CONTROL_PIN 8 //is pwm (servo)

// O2 stepper motor, needs 4 pins
#define O2_CONTROL_PIN0 42
#define O2_CONTROL_PIN1 44
#define O2_CONTROL_PIN2 43
#define O2_CONTROL_PIN3 41

#define O2_ENABLE1_PIN 2
#define O2_ENABLE2_PIN 3

#define FLOW_COEFFICIENT 1

#define HOME_SWITCH_PIN 28

// Stepper and Servo initialization
#define O2_STEPPER_SPEED 60 // rpm (TODO: Arbitrary value)

#define PI_MAX_WAIT_TIME 1000
#define STEPPER_INITIALIZATION_TIMEOUT 360 // Assuming there are 360 steps in a rotation, one full rotation = timed out (TODO: Arbitrary value)

// https://www.arduino.cc/en/Reference/ServoWrite
#define BLOW_FAN_INITIAL_POSITION 15  // 0 = min, 180 = max, 90 = midpoint (TODO: this is currently arbitrary)
#define AIR_INTAKE_INITIAL_POSITION 110 // 0 = min, 180 = max, 90 = midpoint (TODO: arbitraty)

#define TIMEOUT_ERROR -1


#endif