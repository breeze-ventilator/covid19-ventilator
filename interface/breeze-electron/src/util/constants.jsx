export const colors = {
  white: "#ffffff",
  bluePurple: "#6500ff",
  weirdGreen: "#3dd598",
  charcoalGrey: "#44444f",
  blueyGrey: "#92929d",
  paleLilac: "#e2e2ea",
  softBlue: "#50b5ff",
  brightBlue: "#0062ff",
  lightGreyBlue: "#b5b5be",
  paleGrey: "#fafafb",
  dark: "#171725",
  grapefruit: "#fc5a5a",
  darkRed: "#e15a54",
  darkBlue: "#293859",
  black: "#000000",
  green: "#7caa55",
  lightGreen: "#DEEAD4",
  homeGreen: "#419D55",
  homeGrey: "#767676",
  backgroundGrey: "#F7F7F7",
  borderGrey: "#C4C4C4",
  lightGrey: "#eeeef0",
  orange: "#FF7A00",
  lightOrange: "#FFECDA",
};

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
  fiO2: {
    readableName: "FiO2",
    unit: "%",
    min: 0,
    max: 100,
    recMin: 50,
    recMax: 60,
  }, // min and max that can be set on the interface
  peep: {
    readableName: "PEEP",
    unit: "cm H2O",
    min: 0,
    max: 100,
    recMin: 50,
    recMax: 60,
  },
  inspiratoryPressure: {
    readableName: "Inspiratory pressure",
    unit: "cm H2O",
    min: 0,
    max: 100,
    recMin: 50,
    recMax: 60,
  },
  inspiratoryTime: {
    readableName: "Inspiratory time",
    unit: "%",
    min: 0,
    max: 100,
    recMin: 50,
    recMax: 60,
  },
  respiratoryRate: {
    readableName: "Respiratory rate",
    unit: "bpm",
    min: 0,
    max: 100,
    recMin: 50,
    recMax: 60,
  },
  sensitivity: {
    readableName: "Sensitivity",
    unit: "L/min",
    min: 0,
    max: 100,
    recMin: 50,
    recMax: 60,
  },
  apneaTime: {
    readableName: "Apnea time",
    unit: "s",
    min: 0,
    max: 100,
    recMin: 50,
    recMax: 60,
  },
  flowCyclingOff: {
    readableName: "Flow cycling off",
    unit: "",
    min: 0,
    max: 100,
    recMin: 50,
    recMax: 60,
  },
};
