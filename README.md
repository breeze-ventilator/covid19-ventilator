#  Breeze Ventilator
This is the repository for all of the Breeze Ventilator code. It contains code for both the firmware, which runs on an Arduino Mega, and the Breeze interface app, which runs on a Raspberry Pi 4.

## Firmware for Arduino
The Arduino firmware has several components:
* `Controller` controls the blower fan (`BlowerControl`) using PID, the alarm (`AlarmControl`), the battery charging (`BatteryChargingControl`), the oxygen intake (`OxygenControl`), and the air intake (`AirIntake`)
* `Sensors` reads from the various sensors: `BatteryVoltageSensor` for getting the battery percentage, `FlowSensor` for measuring flow and tidal volume, `PressureSensor`, and `OxygenSensor`
* `PiCommunication` communicates with a Raspberry Pi running the Breeze app over the serial port. Every second, the Arduino sends data to the Pi, and the Pi either replies with new parameters or a standard message indicating that the Pi has not crashed.
* `State` modifies the state of the system based on the parameters, the time, and the sensor data. The state cycles between inhalation and exhalation.
* `Data` saves a short history of the data from the sensors and computes a moving average for the pressure and flow readings.
* `Parameters` contains all the parameters given by the Raspberry Pi. New parameters from the Raspberry Pi get updated upon the start of a new breath.

## Interface
To run the interface for the first time:
1. `cd interface/breeze-electron`
2. `npm install`, which might take a few minutes.
3. `npm run start`
A popup error will appear at the start if it hasn't detected the Arduino plugged in or if it can't find `arduino_messager.py`. You can close the error and the rest of the app will remain functional.
