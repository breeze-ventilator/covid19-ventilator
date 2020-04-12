#include "State.h"

State::State() {
  breathCompleted = true;
  startTime = 0;
  breathingStage = INHALATION_STAGE;
}

void State::updateState(Parameters &parameters) {
  unsigned long currentTime = millis();
  if (parameters.currentMode == PRESSURE_CONTROL_MODE) {
    // checks time to see if time to switch from inhalation to exhilation
    if (breathingStage == INHALATION_STAGE) {
      setDesiredPressure(parameters);
      if (isFinishedInspiratoryStageInPressureControl(parameters)) {
        endInhalationAndStartExhalation();
        startTime = currentTime;
      }
    }
    else if (breathingStage == EXHALATION_STAGE && isFinishedExpiratoryStageInPressureControl(parameters)) {
      endExhalationAndStartInhalation();
      startTime = currentTime;
    }
  }
  else if (parameters.currentMode == PRESSURE_SUPPORT_MODE) {
    // TODO: should use state.lastFlowValue, state.peakFlowValueInCurrentBreath

  }
}

void State::setDesiredPressure(Parameters &parameters) {
  unsigned long elapsedTime = millis() - startTime;
  float slope = (float) parameters.currentInspiratoryPressure / parameters.currentRiseTime;
  desiredPressure = parameters.currentPEEP + slope*elapsedTime;
}

void State::setBreathCompletedToFalse() {
  breathCompleted = false;
}

void State::endInhalationAndStartExhalation() {
  breathingStage = EXHALATION_STAGE;
}

void State::endExhalationAndStartInhalation() {
  breathingStage = INHALATION_STAGE;
  breathCompleted = true;
}

int State::isFinishedInspiratoryStageInPressureControl(Parameters &parameters) {
  return isTime(startTime, parameters.currentInspiratoryTime);
}

int State::isFinishedExpiratoryStageInPressureControl(Parameters &parameters) {
  return isTime(startTime, parameters.currentMaxExpiratoryTime);
}

// int State::isFinishedInspiratoryStageInPressureSupport(Parameters &parameters) {
//   return isTime(startTime, parameters.currentInspiratoryTime);
// }

// int State::isFinishedExpiratoryStageInPressureSupport(Parameters &parameters) {
//   return isTime(startTime, parameters.currentExpiratoryTime);
// }