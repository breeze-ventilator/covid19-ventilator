#ifndef SENSORS_H
#define SENSORS_H

#define SECONDS_TO_MILLISECONDS 1000
#define MINUTES_TO_MILLISECONDS 60000

#define FLOW_IC2_ADDRESS 64//TODO: SIMON
#define FLOW_OFFSET 32768
#define FLOW_SCALE 120
#define OXYGEN_PRESSURE_SENSOR_PIN 7
#define BATTERY_VOLTAGE_PIN 8

#include "../OxygenPressureSensor/OxygenPressureSensor.h"
#include "../FlowSensor/FlowSensor.h"
#include "../BatteryVoltageSensor/BatteryVoltageSensor.h"
#include "../MainPressureSensor/MainPressureSensor.h"
#include "../Data/Data.h"
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
        // BatteryVoltageSensor batteryVoltageSensor;
        
        void init();
        void readSensorsIfAvailableAndSaveSensorData(Data &data);

    private:
        int isTimeToReadFlow();
        int isTimeToReadMainPressure();
        int isTimeToReadOxygenPressure();
        int isTimeToReadBatteryPercentage();
        int isTimeToRead(unsigned long lastReadTime, unsigned int timeBetweenReadings);
        
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