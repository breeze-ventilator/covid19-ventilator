#include "miscallaneous.h"

/*
  Sets the new parameters based on the parameters string.

  https://docs.google.com/document/d/17tNHzC1KAyru91LCRugWpDMOWfZAJPe1F5hpNLfNYW8/edit#
*/

void initializeSensors(struct Sensors *sensors) {
	
}

void setNewParameters(String piString, struct parameters *newParams){
  if (!isChecksumValid(piString)) {
    // @TODO: Determine what to do if checksum wrong.
    return;
  }

  // Set parameters.
  newParams->mode = piString.charAt(1);
  newParams->fiO2 = piString.charAt(2);
  newParams->inspiratoryTime = piString.charAt(3);
  newParams->expiratoryTime = piString.charAt(4);
  newParams->peakInspiratoryPressure = piString.charAt(5);
  newParams->peakExpiratoryPressure = piString.charAt(6);
  newParams->sensitivity = piString.charAt(7);
  newParams->alarms.highPressureBound = piString.charAt(8);
  newParams->alarms.lowPressureBound = piString.charAt(9);
  newParams->alarms.highMinuteVentilationBound = piString.charAt(10);
  newParams->alarms.lowMinuteVentilationBound = piString.charAt(11);
  
  return;
}

// deep copy of new parameters to current parameters
updateCurrentParameters(struct parameters *currentParams, struct parameters *newParams) {
	currentParams->mode = newParams->mode;
  currentParams->fiO2 = newParams->fiO2;
  currentParams->inspiratoryTime = newParams->inspiratoryTime;
  currentParams->expiratoryTime = newParams->expiratoryTime;
  currentParams->peakInspiratoryPressure = newParams->peakInspiratoryPressure;
  currentParams->peakExpiratoryPressure = newParams->peakExpiratoryPressure;
  currentParams->sensitivity = newParams->sensitivity;
  currentParams->alarms.highPressureBound = newParams->newParams.highPressureBound;
  currentParams->alarms.lowPressureBound = newParams->newParams.lowPressureBound;
  currentParams->alarms.highMinuteVentilationBound = newParams->newParams.highMinuteVentilationBound;
  currentParams->alarms.lowMinuteVentilationBound = newParams->newParams.lowMinuteVentilationBound;
	return;
}