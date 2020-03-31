#ifndef STATE_H
#define STATE_H

#define PRESSURE_SUPPORT_MODE 1
#define PRESSURE_CONTROL_MODE 2
#define INHILATION_STAGE 3
#define EXHALATION_STAGE 4

class State {
    public:
        bool isStartingNewBreath;
        unsigned long startTime;
        unsigned int breathingStage; // inhilation or exhilation
    private:
        void updateState(Parameters *parameters);
        void State::endInhilationAndStartExhalation();
        void State::endExhalationAndStartInhilation();
        int State::finishedInspiratoryStage(unsigned long currentTime, Parameters *parameters);
        int State::finishedExpiratoryStage(unsigned long currentTime, Parameters *parameters);
}

#endif