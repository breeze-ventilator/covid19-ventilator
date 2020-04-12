#include "helpers.h"

int isTime(unsigned long lastTime, unsigned int timeBetweenReadings) {
  unsigned long currentTime = millis();
  unsigned long timeDifference = currentTime - lastTime;
  if (timeDifference >= timeBetweenReadings) {
    return 1;
  }
  else {
    return 0;
  }
}