#ifndef CONTROLS_H
#define CONTROLS_H

#define OXYGEN_VALVE_MOTOR_INTERFACE_TYPE 4
#define OXYGEN_VALVE_PIN0 42
#define OXYGEN_VALVE_PIN1 44
#define OXYGEN_VALVE_PIN2 43
#define OXYGEN_VALVE_PIN3 41
#define OXYGEN_VALVE_LIMIT_SWITCH_PIN 28
#define OXYGEN_VALVE_MAX_STEPPER_SPEED 1000
#define OXYGEN_VALVE_STEPPER_ACCELERATION 300
#define OXYGEN_VALVE_ENABLE1_PIN 2
#define OXYGEN_VALVE_ENABLE2_PIN 3
#define AIR_INTAKE_PIN 8
#define BLOWER_FAN_PIN 9
#define AIR_INTAKE_ZERO_POINT 110
#define TIME_BETWEEN_OXYGEN_CONTROLS 100 // ms
#define TIME_BETWEEN_AIR_CONTROLS 100 // ms

class Controller {
    public:
        Controller();
        void init();
        void stopArduinoAlarm();
        void ringAlarmForever();
        void inhilationControl(Data *data, Parameters *parameters, State *state);
        void exhalationControl(Data *data, Parameters *parameters, State *state)
    private:
        void oxygenControl(Data *data, Parameters *parameters, State *state);
        void airControl(Parameters *parameters);
        int isTimeToControlOxygen();
        int isTimeToControlAir();
        int isTimeToRead(unsigned long lastReadTime, int timeBetweenReadings);

        OxygenValveStepper OxygenValveStepper;
        Alarm alarm;
        AirIntakeServo airIntakeServo;
        BlowerFanServo blowerFanServo; 
        BlowerPID blowerPID;
        int _lastOxygenControlTime;
        int _lastAirControlTime;
};

#endif