/*
  Initializes the pins for the arduino.
*/
void initializeDigitalPins() {
  // https://www.arduino.cc/en/Tutorial/DigitalPins

  // inputs/measurements
  pinMode(FAN_SENSOR_PIN, INPUT_PULLUP);

  // outputs/controls
  pinMode(ALARM_PIN, OUTPUT);
  pinMode(O2_ENABLE1_PIN, OUTPUT);
  pinMode(O2_ENABLE2_PIN, OUTPUT);
}