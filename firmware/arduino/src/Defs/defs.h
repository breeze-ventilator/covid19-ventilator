#ifndef INIT_H
#define INIT_H

#define PARAMETER_BYTE_LENGTH 13

#define SECONDS_TO_MILLISECONDS 1000
#define MINUTES_TO_MILLISECONDS 60000
#define CENTIMETERS_TO_MILIMETERS 10
#define TENTH_OF_SECOND_TO_MILISECONDS 100

#define OFF_MODE 0
#define PRESSURE_CONTROL_MODE 1
#define PRESSURE_SUPPORT_MODE 2
#define INHALATION_STAGE 3
#define EXHALATION_STAGE 4
#define OFF_STAGE 5

#define NUM_OF_PRESSURE_MEASUREMENTS 10 
#define NUM_OF_FLOW_MEASUREMENTS 10 

#define SEND_DATA_TIMEOUT 10

// Input pin numbers
#define MAIN_PRESSURE_PIN 6

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

#define STEPPER_INITIALIZATION_TIMEOUT 360 // Assuming there are 360 steps in a rotation, one full rotation = timed out (TODO: Arbitrary value)

// https://www.arduino.cc/en/Reference/ServoWrite
#define BLOW_FAN_INITIAL_POSITION 15  // 0 = min, 180 = max, 90 = midpoint (TODO: this is currently arbitrary)
#define AIR_INTAKE_INITIAL_POSITION 110 // 0 = min, 180 = max, 90 = midpoint (TODO: arbitraty)

#define FLOW_READING_FREQUENCY 500 // 500 Hz
#define MAIN_PRESSURE_READING_FREQUENCY 500// 500 TODO: change
#define OXYGEN_READING_FREQUENCY 5
#define BATTERY_VOLTAGE_READING_FREQUENCY 5

// Pi Comms
#define BAUD_RATE 9600
#define PI_PING_INTERVAL 100
#define TIME_BETWEEN_DATA_SENDING_TO_PI 1000

// Pressure support
#define MIN_INHALATION_TIME_PRESSURE_SUPPORT 400

#endif