#ifndef STATE_H
#define STATE_H

#include "../Parameters/Parameters.h"
#include "../Defs/defs.h"
#include "../Helpers/helpers.h"
#include "../Data/Data.h"
#include "../Defs/errors.h"

#include <math.h>

class State {
    public:
        State();
        int breathCompleted;
        unsigned long startTime;
        int breathingStage; // inhalation or exhilation
        uint32_t desiredPressure;
        int mode;
        float maxFlowDuringInhalation;
        int apneaTimeExceededError;
        
        void updateState(Parameters &parameters, Data &data);
    
    private:
        void setDesiredInhalationPressure(Parameters &parameters);
        void endInhalationAndStartExhalation();
        void endExhalationAndStartInhalation();
        int isFinishedInspiratoryStageInPressureControl(Parameters &parameters);
        int isFinishedExpiratoryStageInPressureControl(Parameters &parameters, Data &data);
        int patientTriggeredBreath(Parameters &parameters, Data &data);
        void resetMaxFlow();
        void updateMaxFlow(Data &data);
        int isApneaTimeExceeded(Parameters &parameters);

        int isFinishedInspiratoryStageInPressureSupport(Parameters &parameters, Data &data);
        int isFinishedExpiratoryStageInPressureSupport(Parameters &parameters, Data &data);
        void emergencySwitchToPatientControl(Parameters &parameters);
};

#endif