#include "State.h"
#include "Parameters.h"

State::State() {
  isStartingNewBreath = false;
  startTime = 0;
  breathingStage = INHILATION_STAGE;
}

State::updateState(Parameters parameters) {
  unsigned long currentTime = millis();
  if (parameters.mode == PRESSURE_CONTROL_MODE) {
    // checks time to see if time to switch from inhilation to exhilation
    if (breathingStage == INHILATION_STAGE && finishedInspiratoryStage(currentTime)) {
      endInhilationAndStartExhalation();
      startTime = currentTime;
    }
    else if (breathingStage == EXHALATION_STAGE && finishedExpiratoryStage(currentTime)) {
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

State::endInhilationAndStartExhalation() {
  breathingStage = EXHALATION_STAGE;
}

State::endExhalationAndStartInhilation() {
  breathingStage = INHILATION_STAGE;
  isStartingNewBreath = true;
}

State::finishedInspiratoryStage(currentTime) {
  if (currentTime - startTime > currentParams.inspiratoryTime) {
    return 1;
  } else {return 0;}
}

State::finishedExpiratoryStage(currentTime) {
  if (currentTime - startTime > currentParams.expiratoryTime) {
    return 1;
  } else {return 0;}
}