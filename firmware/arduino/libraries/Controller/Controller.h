#ifndef CONTROLS_H
#define CONTROLS_H

class Controller {
    public:
        Controller();
    private:
        OxygenValveStepper OxygenValveStepper;
        Alarm alarm;
        AirIntakeServo airIntakeServo;
        BlowerFanServo blowerFanServo; 
        BlowerPID blowerPID;
}

#endif