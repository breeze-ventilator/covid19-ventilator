#ifndef SENSORS_H
#define SENSORS_H

class Data {
    private:
        unsigned int _batteryVoltage;
        float _lastFlowValue;
        unsigned int _peakFlowValueInCurrentBreath; // needed for switching to exhalation
        
        // for PID
        std::list<float> _flowValues;
        std::list<unsigned int> _pressureValues;
        
        // for Pi
        float _flowSum;
        unsigned int _pressureSum;
        unsigned int _numFlowMeasurements;
        unsigned int _numPressureMeasurements;
        unsigned int _numFlowErros;
        unsigned int _numPressureErrors;
}

#endif