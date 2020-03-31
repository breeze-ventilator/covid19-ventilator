#ifndef PARAMETERS_H
#define PARAMETERS_H

class Parameters {
    public:
        unsigned int currentMode;
        unsigned int currentMiO2;
        unsigned int currentInspiratoryTime;
        unsigned int currentMxpiratoryTime;
        unsigned int currentPeakInspiratoryPressure;
        unsigned int currentPeakExpiratoryPressure;
        unsigned int currentSensitivity;
    private:
        unsigned int _newMode;
        unsigned int _newFiO2;
        unsigned int _newInspiratoryTime;
        unsigned int _newExpiratoryTime;
        unsigned int _newPeakInspiratoryPressure;
        unsigned int _newPeakExpiratoryPressure;
        unsigned int _newSensitivity;
}

#endif