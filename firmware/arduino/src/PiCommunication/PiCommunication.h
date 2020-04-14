#ifndef PI_COMMUNICATION_H
#define PI_COMMUNICATION_H

#define LITERS_TO_TENTH_OF_A_LITER 10

#include "../Defs/errors.h"
#include "../Data/Data.h"
#include "../State/State.h"
#include "../Defs/errors.h"
#include "../Defs/defs.h"
#include "../Helpers/helpers.h"
#include <math.h>

#include "../Parameters/Parameters.h" // TODO: remove

#define MAX_SERIAL_WAIT_TIME 1000
#define WELCOME_MESSAGE 200
#define CONNECTED_MESSAGE 2
#define WRONG_RESPONSE_MESSAGE 3
#define MESSAGE_LENGTH_FROM_PI 14

class PiCommunication {
    public: 
        PiCommunication(int baudRate, int timeBetweenPiSending);
        int initCommunication(int pingInterval);
        void getParametersFromPi();
        void tellPiThatWeGotParameters();
        void sendDataToPi(Data &data, State &state);
        int isPiSendingUsNewParameters();
        char getMessageType();
        void flush();
        int isDataAvailable();
        void updateValuesForPiUponBreathCompleted(Data &data, State &state);
        
        // int isChecksumValid(String piString);
        int isTimeToSendDataToPi();
        uint8_t parametersBuffer[PARAMETER_BYTE_LENGTH];
    private:
        void resetValuesForPi();
        int _baudRate;
        unsigned long _timeBetweenPiSending;
        unsigned long _lastSentDataTime;
        uint8_t _breathCompletedToSend;
        uint8_t _tidalVolumeToSend;
};

#endif