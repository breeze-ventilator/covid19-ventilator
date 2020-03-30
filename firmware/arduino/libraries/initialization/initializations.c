/*
  Initializes the pins for the arduino.
*/
void initializePins() {
  // https://www.arduino.cc/en/Tutorial/DigitalPins

  // inputs/measurements
  pinMode(PRESSURE_PIN, INPUT);
  pinMode(FLOW_PIN, INPUT);
  pinMode(BATTERY_PIN, INPUT); // TODO: What is the battery pin?
  pinMode(FAN_SENSOR_PIN, INPUT); // TODO: Clarify with Simon how fan pins work?

  // outputs/controls
  pinMode(ALARM_PIN, OUTPUT);
  pinMode(BLOWER_PIN, OUTPUT); // TODO: Are we controlling two fans?
  pinMode(O2_CONTROL_PIN0, OUTPUT);
  pinMode(O2_CONTROL_PIN1, OUTPUT);
  pinMode(O2_CONTROL_PIN2, OUTPUT);
  pinMode(O2_CONTROL_PIN3, OUTPUT);
  pinMode(AIR_CONTROL_PIN, OUTPUT);
}