#ifndef SENSORS_H
#define SENSORS_H

class Data {
    public:
        unsigned int batteryVoltage;
        float lastFlowValue;
        unsigned int peakFlowValueInCurrentBreath; // needed for switching to exhalation
        
        // for PID
        std::list<float> flowValues;
        std::list<unsigned int> pressureValues;
        
        // for Pi
        float flowIntegral;
        unsigned int pressureSum;
        unsigned int numPressureMeasurements;
        unsigned int numFlowErros;
        unsigned int numPressureErrors;
        unsigned int batteryPercentage;
}

#endif