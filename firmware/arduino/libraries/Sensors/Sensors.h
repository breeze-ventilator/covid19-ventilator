#ifndef SENSORS_H
#define SENSORS_H

#define SECONDS_TO_MILLISECONDS 1000
#define MINUTES_TO_MILLISECONDS 60000

#define FLOW_IC2_ADDRESS //TODO: SIMON
#define FLOW_OFFSET
#define FLOW_SCALE
#define OXYGEN_PRESSURE_SENSOR_PIN
#define BATTERY_VOLTAGE_PIN

class Sensors {
    public:
        Sensors(int flowReadingFrequency,
                 int mainPressureReadingFrequency,
                 int oxygenPressureReadingFrequency,
                 int batteryVoltageReadingFrequency);
        FlowSensor flowSensor;
        MainPressureSensor mainPressureSensor;
        OxygenPressureSensor oxygenPressureSensor;
        
        void init();
        void readSensorsIfAvailableAndSaveSensorData(Data *data);

    private:
        int isTimeToReadFlow();
        int isTimeToReadMainPressure();
        int isTimeToReadOxygenPressure();
        int isTimeToReadBatteryPercentage();
        int isTimeToRead(unsigned long lastReadTime, int timeBetweenReadings);
        
        int _timeBetweenFlowReadings;
        int _timeBetweenMainPressureReadings;
        int _timeBetweenOxygenPressureReadings;
        int _lastFlowReadTime;
        int _lastMainPressureReadTime;
        int _lastOxygenPressureReadTime;
        int _batteryVoltageReadTime;

};

#endif