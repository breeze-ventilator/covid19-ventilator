#include "State.h"

State::State() {
  mode = OFF_MODE;
  breathCompleted = 1;
  startTime = 0;
  breathingStage = OFF_STAGE;
}

void State::updateState(Parameters &parameters, Data &data) {
  if ((mode != PRESSURE_CONTROL_MODE && mode != PRESSURE_SUPPORT_MODE)
        && 
        (parameters.currentMode == PRESSURE_CONTROL_MODE
        || parameters.currentMode == PRESSURE_SUPPORT_MODE))
  {
    // start with inhalation
    breathingStage = INHALATION_STAGE;
    startTime = millis();

  }
  mode = parameters.currentMode;
  if (parameters.currentMode == PRESSURE_CONTROL_MODE) {
    // checks time to see if time to switch from inhalation to exhilation
    if (breathingStage == INHALATION_STAGE) {
      breathCompleted = 0;
      setDesiredPressure(parameters);
      if (isFinishedInspiratoryStageInPressureControl(parameters)) {
        endInhalationAndStartExhalation();
      }
    }
    else if (breathingStage == EXHALATION_STAGE && isFinishedExpiratoryStageInPressureControl(parameters, data)) {
      endExhalationAndStartInhalation();
    }
  }
  else if (parameters.currentMode == PRESSURE_SUPPORT_MODE) {
    // TODO: should use state.lastFlowValue, state.peakFlowValueInCurrentBreath

  }
}

void State::setDesiredPressure(Parameters &parameters) {
  unsigned long elapsedTime = millis() - startTime;
  float slope = (float) parameters.currentInspiratoryPressure / parameters.currentRiseTime;
  if (desiredPressure < parameters.currentPEEP + parameters.currentInspiratoryPressure) {
    desiredPressure = parameters.currentPEEP + slope*elapsedTime;
  }
  else {
    desiredPressure = parameters.currentPEEP + parameters.currentInspiratoryPressure;
  }
}

void State::endInhalationAndStartExhalation() {
  breathingStage = EXHALATION_STAGE;
  startTime = millis();
}

void State::endExhalationAndStartInhalation() {
  breathingStage = INHALATION_STAGE;
  breathCompleted = 1;
  startTime = millis();
}

int State::isFinishedInspiratoryStageInPressureControl(Parameters &parameters) {
  return isTime(startTime, parameters.currentInspiratoryTime);
}

int State::isFinishedExpiratoryStageInPressureControl(Parameters &parameters, Data &data) {
  if (isTime(startTime, parameters.currentMaxExpiratoryTime)) {
    return 1;
  }
  
  // flow triggering
  if (patientTriggeredBreath(parameters, data)) {
    return 1;
  }
  return 0;
}

int State::patientTriggeredBreath(Parameters &parameters, Data &data) {
  if (data.getFlowRecentHistoryAverage() <= parameters.currentSensitivity) {
    Serial.println(-10);
    return 1;
  }
  else {
    return 0;
  }
}
// int State::isFinishedInspiratoryStageInPressureSupport(Parameters &parameters) {
//   return isTime(startTime, parameters.currentInspiratoryTime);
// }

// int State::isFinishedExpiratoryStageInPressureSupport(Parameters &parameters) {
//   return isTime(startTime, parameters.currentExpiratoryTime);
// }