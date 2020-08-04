#ifndef INIT_H
#define INIT_H

#define PARAMETER_BYTE_LENGTH 13

// Utilities
#define SECONDS_TO_MILLISECONDS 1000
#define MINUTES_TO_MILLISECONDS 60000
#define CENTIMETERS_TO_MILIMETERS 10
#define TENTH_OF_SECOND_TO_MILISECONDS 100

// Modes and breathing stages
#define OFF_MODE 0
#define PRESSURE_CONTROL_MODE 1
#define PRESSURE_SUPPORT_MODE 2
#define INHALATION_STAGE 3
#define EXHALATION_STAGE 4
#define OFF_STAGE 5

// Input pin numbers
#define ALARM_PIN 25
#define AIR_CONTROL_PIN 8 //is pwm (servo)

// Stepper and Servo initialization
#define O2_STEPPER_SPEED 60 // rpm (TODO: Arbitrary value)

// https://www.arduino.cc/en/Reference/ServoWrite
#define AIR_INTAKE_INITIAL_POSITION 110 // 0 = min, 180 = max, 90 = midpoint (TODO: arbitraty)

#define FLOW_READING_FREQUENCY 500 // Hz
#define MAIN_PRESSURE_READING_FREQUENCY 500
#define OXYGEN_READING_FREQUENCY 20
#define BATTERY_VOLTAGE_READING_FREQUENCY 5

// Pi Comms
#define BAUD_RATE 9600
#define PI_PING_INTERVAL 100
#define TIME_BETWEEN_DATA_SENDING_TO_PI 1000

// Pressure support
#define MIN_INHALATION_TIME_PRESSURE_SUPPORT 400

#endif