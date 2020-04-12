#ifndef SENSORS_H
#define SENSORS_H

#define FLOW_IC2_ADDRESS 64//TODO: SIMON
#define FLOW_OFFSET 32768// 32000//32768
#define FLOW_SCALE 120 // for air, 142.8 for O2
#define OXYGEN_PRESSURE_SENSOR_PIN 7
#define BATTERY_VOLTAGE_PIN 8

#include "OxygenPressureSensor/OxygenPressureSensor.h"
#include "FlowSensor/FlowSensor.h"
#include "BatteryVoltageSensor/BatteryVoltageSensor.h"
#include "MainPressureSensor/MainPressureSensor.h"

#include "../Defs/defs.h"
#include "../Data/Data.h"
#include "../Helpers/helpers.h"
#include "Arduino.h"

class Sensors {
    public:
        Sensors(int flowReadingFrequency,
                 int mainPressureReadingFrequency,
                 int oxygenPressureReadingFrequency,
                 int batteryVoltageReadingFrequency);
        FlowSensor flowSensor;
        MainPressureSensor mainPressureSensor;
        // OxygenPressureSensor oxygenPressureSensor;
        BatteryVoltageSensor batteryVoltageSensor;
        
        void init();
        void readSensorsIfAvailableAndSaveSensorData(Data &data);

    private:
        int isTimeToReadFlow();
        int isTimeToReadMainPressure();
        int isTimeToReadOxygenPressure();
        int isTimeToReadBatteryPercentage();
        
        unsigned int _timeBetweenFlowReadings;
        unsigned int _timeBetweenMainPressureReadings;
        unsigned int _timeBetweenOxygenPressureReadings;
        unsigned int _timeBetweenBatteryPercentageReadings;
        unsigned int _timeBetweenPrints;

        unsigned long _lastFlowReadTime;
        unsigned long _lastMainPressureReadTime;
        unsigned long _lastOxygenPressureReadTime;
        unsigned long _lastBatteryPercentageReadTime;
        unsigned long _lastPrintTime;

};

#endif