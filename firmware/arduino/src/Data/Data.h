#ifndef DATA_H
#define DATA_H
#include "List/List.h"
#include "Arduino.h"

#define PRESSURE_HISTORY_LENGTH_FOR_PID 20 //TODO: change
#define FLOW_HISTORY_LENGTH 50
class Data {
    public:
        Data();
        void saveFlowReading(float flowValue);
        void updateTidalVolume(float flowValue, float delta_time);
        void saveMainPressureReading(float pressureValue);
        float getMainPressureAverageForPID();
        float getFlowRecentHistoryAverage();
        void saveBatteryPercentage(unsigned int newBatteryPercentage);
        void saveOxygenReading(float oxygenReading);
        void resetTidalVolume();

        float peakFlowValueInCurrentBreath; // needed for switching to exhalation
        
        // for Pi
        float tidalVolume;
        uint32_t numFlowErros;
        uint32_t numPressureErrors;
        uint8_t batteryPercentage;
        float oxygenReading;

    private:
        List _pressureValues;
        List _flowValues;

};

#endif