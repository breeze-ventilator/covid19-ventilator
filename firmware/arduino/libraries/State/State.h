#ifndef STATE_H
#define STATE_H

class State {
    public:
        bool isStartingNewBreath;
        unsigned long startTime;
        unsigned int breathingStage; // inhilation or exhilation
    }
}

#endif