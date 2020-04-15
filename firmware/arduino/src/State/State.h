#ifndef STATE_H
#define STATE_H

#include "../Parameters/Parameters.h"
#include "../Defs/defs.h"
#include "../Helpers/helpers.h"
#include "../Data/Data.h"

class State {
    public:
        State();
        int breathCompleted;
        unsigned long startTime;
        int breathingStage; // inhalation or exhilation
        uint32_t desiredPressure;
        int mode;
        
        void updateState(Parameters &parameters, Data &data);
    
    private:
        void setDesiredPressure(Parameters &parameters);
        void endInhalationAndStartExhalation();
        void endExhalationAndStartInhalation();
        int isFinishedInspiratoryStageInPressureControl(Parameters &parameters);
        int isFinishedExpiratoryStageInPressureControl(Parameters &parameters, Data &data);
        int patientTriggeredBreath(Parameters &parameters, Data &data);
};

#endif