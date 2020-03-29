/*
    This file is for any misc utility functions that occur repeatedly.
*/
#include <math.h>

double arrayAverage(int arry[], int n){
    double sum;

    for (int i = 0; i < n ; i++){
        sum =+ arry[i];
    }
    return sum / (double) n ;
}
/*
    Creates a checksum based on the elements of the inputted array
*/
int createCheckSum(int dataArry[], int n){
    int checksum = 1;

    // TODO: someone tell me if this isn't dumb as fuck - James
    for (int i = 0; i < n; i++){
        checksum = checksum ^ dataArry[i]; // XOR the checksum with the value
    }
    return checksum; //
}