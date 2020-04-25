#  Breeze Ventilator
This is the repo for all the ventilator code (interface + firmware)

## Firmware for Arduino
The Arduino firmware has several components:
* `Controller` controls the blower fan (`BlowerControl`) using PID, the alarm (`AlarmControl`), the battery charging (`BatteryChargingControl`), the oxygen intake (`OxygenControl`), and the air intake (`AirIntake`)
* `Sensors` reads from the various sensors: `BatteryVoltageSensor` for getting the battery percentage, `FlowSensor` for measuring flow and tidal volume, `PressureSensor`, and `OxygenSensor`
* `PiCommunication` communicates with a Raspberry Pi running the Breeze app over the serial port. Every second, the Arduino sends data to the Pi, and the Pi either replies with new parameters or a standard message indicating that the Pi has not crashed.
* `State` modifies the state of the system based on the parameters, the time, and the sensor data. The state cycles between inhalation and exhalation.
* `Data` saves a short history of the data from the sensors and computes a moving average for the pressure and flow readings.
* `Parameters` contains all the parameters given by the Raspberry Pi. New parameters from the Raspberry Pi get updated upon the start of a new breath.
