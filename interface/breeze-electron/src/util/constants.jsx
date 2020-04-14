export const readings = { tidalVolume: {} }; // TODO: the fields that we monitor

export const controlParams = [
    "fiO2",
    "peep",
    "inspiratoryPressure",
    "inspiratoryTime",
    "respiratoryRate",
  ];

export const supportParams = [
    "fiO2",
    "peep",
    "inspiratoryPressure",
    "sensitivity",
    "apneaTime",
    "flowCyclingOff",
  ];
  
export const parameterInfo = {
  fiO2: { readableName: "FiO2", unit: "%", min: 0, max: 100 }, // min and max that can be set on the interface
  peep: { readableName: "PEEP", unit: "cm H2O", min: 0, max: 100 },
  inspiratoryPressure: {
    readableName: "Inspiratory pressure",
    unit: "cm H2O",
    min: 0,
    max: 100,
  },
  inspiratoryTime: {
    readableName: "Inspiratory time",
    unit: "%",
    min: 0,
    max: 100,
  },
  respiratoryRate: {
    readableName: "Respiratory rate",
    unit: "bpm",
    min: 0,
    max: 100,
  },
  sensitivity: { readableName: "Sensitivity", unit: "L/min", min: 0, max: 100 },
  apneaTime: { readableName: "Apnea time", unit: "s", min: 0, max: 100 },
  flowCyclingOff: {
    readableName: "Flow cycling off",
    unit: "",
    min: 0,
    max: 100,
  },
};