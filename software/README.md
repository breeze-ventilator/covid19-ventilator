# Software
The software is composed of the firmware that runs on an Arduino Mega and the interface that runs on a Raspberry Pi 4. The two components communicate via the serial port.

## Firmware for Arduino
The Arduino firmware has several components:
* `Controller` controls the blower fan (`BlowerControl`) using PID, the alarm (`AlarmControl`), the battery charging (`BatteryChargingControl`), the oxygen intake (`OxygenControl`), and the air intake (`AirIntake`)
* `Sensors` reads from the various sensors: `BatteryVoltageSensor` for getting the battery percentage, `FlowSensor` for measuring flow and tidal volume, `PressureSensor`, and `OxygenSensor`
* `PiCommunication` communicates with a Raspberry Pi running the Breeze app over the serial port. Every second, the Arduino sends data to the Pi, and the Pi either replies with new parameters or a standard message indicating that the Pi has not crashed.
* `State` modifies the state of the system based on the parameters, the time, and the sensor data. The state cycles between inhalation and exhalation.
* `Data` saves a short history of the data from the sensors and computes a moving average for the pressure and flow readings.
* `Parameters` contains all the parameters given by the Raspberry Pi. New parameters from the Raspberry Pi get updated upon the start of a new breath.

To run the firmware:
1. Clone the respository `git clone https://github.com/Open-Breeze/covid19-ventilator.git`
2. Open `arduino.ino` in the Arduino IDE
3. Plug in the Arduino Mega to your laptop and press upload.

## Interface
To run the interface for the first time:
1. Clone the respository: `git clone https://github.com/Open-Breeze/covid19-ventilator.git`
2. `cd covid19-ventilator/interface/breeze-electron`
3. `npm install`, which might take a few minutes.
4. `npm run start`

You will also need to have `node` installed, which you can do [here](https://nodejs.org/en/).

A popup error will appear at the start if it hasn't detected the Arduino plugged in or if it can't find `arduino_messager.py`. You can close the error and the rest of the app will remain functional.
