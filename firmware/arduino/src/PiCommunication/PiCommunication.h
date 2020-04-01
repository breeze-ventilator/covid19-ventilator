#ifndef PI_COMMUNICATIONS_H
#define PI_COMMUNICATIONS_H

#define LITERS_TO_MILLILITERS 1000
#define PI_SENT_WRONG_CODE_ERROR -2
#define TIMEOUT_ERROR -1

#include "../Data/Data.h"
#include "../State/State.h"

class PiCommunication {
    public: 
        PiCommunication(int baudRate, int timeBetweenPiSending);
        int initCommunication(int32_t maxSerialWaitTime, int32_t maxPiWaitTime, int pingInterval);
        int isDataAvailable();
        String getData();
        void tellPiThatWeGotData();
        void sendServosNotConnectedErrorToPi();
        void sendDataToPi(Data data, State state);
        int isChecksumValid(String piString);
        int isTimeToSendDataToPi();
    private:
        int _baudRate;
        unsigned long _timeBetweenPiSending;
        unsigned long _lastSentDataTime;
};

#endif