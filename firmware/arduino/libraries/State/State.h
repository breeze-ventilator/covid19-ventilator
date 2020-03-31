#ifndef STATE_H
#define STATE_H

#define PRESSURE_SUPPORT_MODE 1
#define PRESSURE_CONTROL_MODE 2
#define INHALATION_STAGE 3
#define EXHALATION_STAGE 4

#include "../Parameters/Parameters.h"

class State {
    public:
        bool isStartingNewBreath;
        unsigned long startTime;
        unsigned int breathingStage; // inhalation or exhilation
        void updateState(Parameters *parameters);
    private:
        void endinhalationAndStartExhalation();
        void endExhalationAndStartinhalation();
        int finishedInspiratoryStage(unsigned long currentTime, Parameters *parameters);
        int finishedExpiratoryStage(unsigned long currentTime, Parameters *parameters);
};

#endif