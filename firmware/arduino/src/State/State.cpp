#include "State.h"

State::State() {
  mode = OFF_MODE;
  breathCompleted = 1;
  startTime = 0;
  breathingStage = OFF_STAGE;
  maxFlowDuringInhalation = 0;
  apneaTimeExceededError = NO_ERROR;
  desiredPressure = 0;
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
      setDesiredInhalationPressure(parameters);
      if (isFinishedInspiratoryStageInPressureControl(parameters)) {
        endInhalationAndStartExhalation();
      }
    }
    else if (breathingStage == EXHALATION_STAGE && isFinishedExpiratoryStageInPressureControl(parameters, data)) {
      endExhalationAndStartInhalation();
    }
  }
  else if (parameters.currentMode == PRESSURE_SUPPORT_MODE) {
    // checks time to see if time to switch from inhalation to exhilation
    if (breathingStage == INHALATION_STAGE) {
      breathCompleted = 0;
      setDesiredInhalationPressure(parameters);
      updateMaxFlow(data);
      if (isFinishedInspiratoryStageInPressureSupport(parameters, data)) {
        endInhalationAndStartExhalation();
      }
    }
    else if (breathingStage == EXHALATION_STAGE) {
      if (isFinishedExpiratoryStageInPressureSupport(parameters, data)) {
        endExhalationAndStartInhalation();
        resetMaxFlow();
      }
      else if (isApneaTimeExceeded(parameters)) {
        // TODO: should notify frontend
        emergencySwitchToPatientControl(parameters);
        apneaTimeExceededError = ERROR;
      }
    }
  } else if (parameters.currentMode == OFF_MODE) {
    breathingStage = OFF_STAGE;
  }
}

int State::isApneaTimeExceeded(Parameters &parameters) {
  if (isTime(startTime, parameters.currentApneaTime)) {
    return 1;
  };
  return 0;
}

void State::updateMaxFlow(Data &data) {
  float currentFlow = data.getFlowRecentHistoryAverage();
  if (currentFlow > maxFlowDuringInhalation) {
    maxFlowDuringInhalation = currentFlow;
  }
}

void State::resetMaxFlow() {
  maxFlowDuringInhalation = 0;
}

void State::setDesiredInhalationPressure(Parameters &parameters) {
  unsigned long elapsedTime = millis() - startTime;
  float slope = ((float) parameters.currentInspiratoryPressure) / ((float) parameters.currentRiseTime);

  // uint32_t desiredInspiratoryPressure = min(slope*elapsedTime, parameters.currentInspiratoryPressure);
  // desiredPressure = desiredInspiratoryPressure + parameters.currentPEEP;
  desiredPressure = parameters.currentInspiratoryPressure + parameters.currentPEEP;
  // Serial.println(desiredPressure);
}

void State::endInhalationAndStartExhalation() {
  breathingStage = EXHALATION_STAGE;
  desiredPressure = 0;
  startTime = millis();
}

void State::endExhalationAndStartInhalation() {
  breathingStage = INHALATION_STAGE;
  breathCompleted = 1;
  startTime = millis();
}

// TODO: need to check for apnea time
int State::isFinishedInspiratoryStageInPressureSupport(Parameters &parameters, Data &data) {
  float currentFlow = data.getFlowRecentHistoryAverage();
  if (isTime(startTime, MIN_INHALATION_TIME_PRESSURE_SUPPORT) && currentFlow < parameters.currentFlowCyclingOffPercentage * maxFlowDuringInhalation) {
    return 1;
  }
  return 0;
}

int State::isFinishedExpiratoryStageInPressureSupport(Parameters &parameters, Data &data) {
  // flow triggering
  if (patientTriggeredBreath(parameters, data)) {
    return 1;
  }
  return 0;
}

int State::isFinishedInspiratoryStageInPressureControl(Parameters &parameters) {
  return isTime(startTime, parameters.currentInspiratoryTime);
}

void State::emergencySwitchToPatientControl(Parameters &parameters) {
  // takes default parameters from the screen
  parameters.currentMode = PRESSURE_CONTROL_MODE;
  breathingStage = INHALATION_STAGE;
  breathCompleted = 1;
  startTime = millis();
}

int State::isFinishedExpiratoryStageInPressureControl(Parameters &parameters, Data &data) {
  if (isTime(startTime, parameters.currentMaxExpiratoryTime)) {
    return 1;
  }
  
  // flow triggering
  // if (patientTriggeredBreath(parameters, data)) {
  //   return 1;
  // }
  return 0;
}

int State::patientTriggeredBreath(Parameters &parameters, Data &data) {
  if (data.getFlowRecentHistoryAverage() <= parameters.currentSensitivity) {
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