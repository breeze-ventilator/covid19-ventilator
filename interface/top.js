const path = require('path');
const express = require('express');
const http = require('http');

const ArduinoMessager = require('./modules/arduino-messager.js');
const ClientMessager = require('./modules/client-messager.js');

module.exports = class Top {
  constructor() {
    // TODO: move to config file
    this.port = 5000;
    this.serialPort = '/dev/ttyACM0';
    this.baudRate = 9600;
    this.maxArduinoPingTime = 1500;

    // this.expressApp = express();
    // this.httpServer = http.createServer(this.expressApp);

    this.client = new ClientMessager(this);
    // this.arduino = new ArduinoMessager(this);

    this.client.setupIO(this.port);
  }

  // TODO: change newParameters to the params.
  handleNewParameters(newParameters){
    this.arduino.handleNewParameters(newParameters)
  }

  handleNewReadings(pressure, flow, batteryVoltage, error){
    this.client.handleNewReadings(pressure, flow, batteryVoltage, error);
  }

}


