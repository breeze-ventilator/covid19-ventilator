#ifndef PI_COMMUNICATION_H
#define PI_COMMUNICATION_H

#define LITERS_TO_MILLILITERS 1000

#include "../Defs/errors.h"
#include "../Data/Data.h"
#include "../State/State.h"
#include "../Defs/errors.h"
#include "../Helpers/helpers.h"
#include <math.h>

#define MAX_SERIAL_WAIT_TIME 1000


class PiCommunication {
    public: 
        PiCommunication(int baudRate, int timeBetweenPiSending);
        int initCommunication(int pingInterval);
        int isDataAvailable();
        String getDataFromPi();
        void tellPiThatWeGotParameters();
        void sendDataToPi(Data &data, State &state);
        int doesMessageContainNewParameters(String receivedString);
        int doesMessageTellUsThatPiIsAwake(String receivedString);
        
        // int isChecksumValid(String piString);
        int isTimeToSendDataToPi();
    private:
        int _baudRate;
        unsigned long _timeBetweenPiSending;
        unsigned long _lastSentDataTime;
};

#endif