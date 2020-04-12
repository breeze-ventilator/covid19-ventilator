#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "../Defs/defs.h"
#include "Arduino.h"
class Parameters {
    public:
        Parameters();
        void getNewParameters(String receivedString);
        void updateCurrentParameters();
        bool newParamsHaveArrived;

        uint8_t currentMode;
        uint8_t currentFiO2;
        uint8_t currentInspiratoryTime;
        uint8_t currentMaxExpiratoryTime;
        uint8_t currentInspiratoryPressure;
        uint8_t currentPEEP;
        uint8_t currentSensitivity;
        uint8_t currentApneaTime;
        uint16_t currentRiseTime;
        uint8_t currentFlowCyclingOffPercentage;
        uint8_t currentHighInspiratoryPressureAlarm;
        uint8_t currentLowExpiratoryPressureAlarm;
    
    private:
        uint8_t _newMode;
        uint8_t _newFiO2;
        uint8_t _newInspiratoryTime;
        uint8_t _newMaxExpiratoryTime;
        uint8_t _newInspiratoryPressure;
        uint8_t _newPEEP;
        uint8_t _newSensitivity;
        uint8_t _newApneaTime;
        uint16_t _newRiseTime;
        uint8_t _newFlowCyclingOffPercentage;
        uint8_t _newHighInspiratoryPressureAlarm;
        uint8_t _newLowExpiratoryPressureAlarm;

};

#endif