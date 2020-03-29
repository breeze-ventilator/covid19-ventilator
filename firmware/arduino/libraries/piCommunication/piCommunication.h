#ifndef PI_H
#define PI_H

//Define functions that will be called in other files here

//
int initializePiCommunication();




void sendData(pressureAvg, flowAvg);

String getPiString();

void parsePiString( String recievedString);


#endif