
export function shouldAlarm(name, value, alarmRanges){
  if (name == "abnormalPressure" && value < alarmRanges.pressure.min) { // workaround: abnormalPressure contains min
    return "Pressure abnormally low"
  }
  if (name == "abnormalFiO2" && value > alarmRanges.pressure.max) {
    return "Pressure abnormally high"
  }
  if (name == "Minute ventilation") {
    if (value < alarmRanges[name].min) {
      return "Minute ventilation low"
    }
    if (value > alarmRanges[name].max) {
      return "Minute ventilation high"
    }
  }
}
