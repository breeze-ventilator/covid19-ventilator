#include "State.h"
#include "Parameters.h"

State::State() {
  isStartingNewBreath = false;
  startTime = 0;
  breathingStage = INHILATION_STAGE;
}

void State::updateState(Parameters *parameters) {
  unsigned long currentTime = millis();
  if (parameters.mode == PRESSURE_CONTROL_MODE) {
    // checks time to see if time to switch from inhilation to exhilation
    if (breathingStage == INHILATION_STAGE && finishedInspiratoryStage(currentTime, &parameters)) {
      endInhilationAndStartExhalation();
      startTime = currentTime;
    }
    else if (breathingStage == EXHALATION_STAGE && finishedExpiratoryStage(currentTime, &parameters)) {
      endExhalationAndStartInhilation();
      startTime = currentTime;
    } else if (isStartingNewBreath) {
      isStartingNewBreath = false;
    }
  }
  else if (parameters.mode == PRESSURE_SUPPORT_MODE) {
    // should use state.lastFlowValue, state.peakFlowValueInCurrentBreath
  }
}

void State::endInhilationAndStartExhalation() {
  breathingStage = EXHALATION_STAGE;
}

void State::endExhalationAndStartInhilation() {
  breathingStage = INHILATION_STAGE;
  isStartingNewBreath = true;
}

int State::finishedInspiratoryStage(unsigned long currentTime, Parameters *parameters) {
  if (currentTime - startTime > parameters.inspiratoryTime) {
    return 1;
  } else {return 0;}
}

int State::finishedExpiratoryStage(unsigned long currentTime, Parameters *parameters) {
  if (currentTime - startTime > parameters.expiratoryTime) {
    return 1;
  } else {return 0;}
}