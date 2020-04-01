#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "Arduino.h"
class Parameters {
    public:
        Parameters();
        void getNewParameters(String receivedString);
        void updateCurrentParameters();
        bool newParamsHaveArrived;

        unsigned int currentMode;
        unsigned int currentFiO2;
        unsigned int currentInspiratoryTime;
        unsigned int currentExpiratoryTime;
        unsigned int currentPeakInspiratoryPressure;
        unsigned int currentPEEP;
        unsigned int currentSensitivity;
    private:
        unsigned int _newMode;
        unsigned int _newFiO2;
        unsigned int _newInspiratoryTime;
        unsigned int _newExpiratoryTime;
        unsigned int _newPeakInspiratoryPressure;
        unsigned int _newPEEP;
        unsigned int _newSensitivity;
};

#endif