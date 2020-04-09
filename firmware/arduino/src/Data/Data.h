#ifndef DATA_H
#define DATA_H
#include "../List/List.h"
#include "Arduino.h"

#define PRESSURE_HISTORY_LENGTH_FOR_PID 50 //TODO: change
class Data {
    public:
        Data();
        void saveFlowReading(float flowValue, float delta_time);
        void saveMainPressureReading(unsigned int pressureValue);
        float getMainPressureAverageForPID();
        void saveBatteryPercentage(unsigned int newBatteryPercentage);
        void saveOxygenPressureReading(unsigned int pressureValue);
        void resetPiDataExceptFlow();
        void resetPiFlowData();

        float lastFlowValue;
        unsigned int peakFlowValueInCurrentBreath; // needed for switching to exhalation
        
        // for PID
        // TODO CHANGE std::list<unsigned int> pressureValues;
        
        // for Pi
        float flowIntegral;
        unsigned int pressureSum;
        unsigned int numPressureMeasurements;
        unsigned int numFlowErros;
        unsigned int numPressureErrors;
        unsigned int batteryPercentage;

    private:
        List _pressureValues;

};

#endif