#ifndef SENSORS_H
#define SENSORS_H

#define FLOW_IC2_ADDRESS 64
#define FLOW_OFFSET 32768// 32000//32768 // we read 32704-32720
#define FLOW_SCALE 120 // for air, 142.8 for O2
#define BATTERY_VOLTAGE_PIN 7
#define OXYGEN_SENSOR_PIN 5

#include "FlowSensor/FlowSensor.h"
#include "BatteryVoltageSensor/BatteryVoltageSensor.h"
#include "MainPressureSensor/MainPressureSensor.h"
#include "OxygenSensor/OxygenSensor.h"

#include "../Defs/defs.h"
#include "../Data/Data.h"
#include "../State/State.h"
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
        // BatteryVoltageSensor batteryVoltageSensor;
        // OxygenSensor oxygenSensor;
        
        void init();
        void readSensorsIfAvailableAndSaveSensorData(Data &data, State &state);

    private:
        int isTimeToReadFlow();
        int isTimeToReadMainPressure();
        int isTimeToReadOxygen();
        int isTimeToReadBatteryPercentage();
        
        unsigned int _timeBetweenFlowReadings;
        unsigned int _timeBetweenMainPressureReadings;
        unsigned int _timeBetweenOxygenReadings;
        unsigned int _timeBetweenBatteryPercentageReadings;
        unsigned int _timeBetweenPrints;

        unsigned long _lastFlowReadTime;
        unsigned long _lastMainPressureReadTime;
        unsigned long _lastOxygenReadTime;
        unsigned long _lastBatteryPercentageReadTime;
        unsigned long _lastPrintTime;

};

#endif