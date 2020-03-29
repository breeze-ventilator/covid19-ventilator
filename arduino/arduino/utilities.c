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