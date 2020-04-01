#include "State.h"

State::State() {
  isStartingNewBreath = false;
  startTime = 0;
  breathingStage = INHALATION_STAGE;
}

void State::updateState(Parameters parameters) {
  unsigned long currentTime = millis();
  if (parameters.currentMode == PRESSURE_CONTROL_MODE) {
    // checks time to see if time to switch from inhalation to exhilation
    if (breathingStage == INHALATION_STAGE && finishedInspiratoryStage(currentTime, parameters)) {
      endinhalationAndStartExhalation();
      startTime = currentTime;
    }
    else if (breathingStage == EXHALATION_STAGE && finishedExpiratoryStage(currentTime, parameters)) {
      endExhalationAndStartinhalation();
      startTime = currentTime;
    } else if (isStartingNewBreath) {
      isStartingNewBreath = false;
    }
  }
  else if (parameters.currentMode == PRESSURE_SUPPORT_MODE) {
    // should use state.lastFlowValue, state.peakFlowValueInCurrentBreath
  }
}

void State::endinhalationAndStartExhalation() {
  breathingStage = EXHALATION_STAGE;
}

void State::endExhalationAndStartinhalation() {
  breathingStage = INHALATION_STAGE;
  isStartingNewBreath = true;
}

int State::finishedInspiratoryStage(unsigned long currentTime, Parameters parameters) {
  if (currentTime - startTime > parameters.currentInspiratoryTime) {
    return 1;
  } else {return 0;}
}

int State::finishedExpiratoryStage(unsigned long currentTime, Parameters parameters) {
  if (currentTime - startTime > parameters.currentExpiratoryTime) {
    return 1;
  } else {return 0;}
}