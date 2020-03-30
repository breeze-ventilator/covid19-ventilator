#ifndef SENSORS_H
#define SENSORS_H

class Sensors {
    public:
        Sensors();
        FlowSensor flowSensor;
        MainPressureSensor mainPressureSensor;
        OxygenPressureSensor oxygenPressureSensor;
}

#endif