#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "../Defs/defs.h"
#include "Arduino.h"
class Parameters {
    public:
        Parameters();
        void getNewParameters(uint8_t parametersBuffer[PARAMETER_BYTE_LENGTH]);
        void updateCurrentParameters();
        bool newParamsHaveArrived;

        uint8_t currentMode;
        uint8_t currentFiO2;
        uint16_t currentInspiratoryTime;
        uint16_t currentMaxExpiratoryTime;
        uint16_t currentInspiratoryPressure;
        uint16_t currentPEEP;
        uint8_t currentSensitivity;
        uint8_t currentApneaTime;
        uint16_t currentRiseTime;
        uint8_t currentFlowCyclingOffPercentage;
        uint16_t currentHighInspiratoryPressureAlarm;
        uint16_t currentLowExpiratoryPressureAlarm;
    
    private:
        uint8_t _newMode;
        uint8_t _newFiO2;
        uint16_t _newInspiratoryTime;
        uint16_t _newMaxExpiratoryTime;
        uint16_t _newInspiratoryPressure;
        uint16_t _newPEEP;
        uint8_t _newSensitivity;
        uint8_t _newApneaTime;
        uint16_t _newRiseTime;
        uint8_t _newFlowCyclingOffPercentage;
        uint16_t _newHighInspiratoryPressureAlarm;
        uint16_t _newLowExpiratoryPressureAlarm;

};

#endif