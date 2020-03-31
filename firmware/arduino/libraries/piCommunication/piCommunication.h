#ifndef PI_COMMUNICATIONS_H
#define PI_COMMUNICATIONS_H

#define LITERS_TO_MILLILITERS 1000
#define PI_SENT_WRONG_CODE_ERROR -2
#define TIMEOUT_ERROR -1

class PiCommunication {
    public: 
        PiCommunication(int baudRate);
        int initCommunication(int maxSerialWaitTime, int maxPiWaitTime, int pingInterval);
        int isDataAvailable();
        String getData();
        void tellPiThatWeGotData();
        void sendServosNotConnectedErrorToPi();
        void sendData(Data *data, State *state);
        int isChecksumValid(String piString);
    private:
        int _baudRate;
};

#endif