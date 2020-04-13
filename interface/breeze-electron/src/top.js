const path = require('path');
const express = require('express');
const http = require('http');

// const ArduinoMessager = require('./modules/arduino-messager.js');
const ClientMessager = require('./modules/client-messager.js');

module.exports = class Top {
  constructor() {
    // TODO: move to config file
    this.port = 5000;
    this.serialPort = '/dev/cu.usbmodem14201';
    this.baudRate = 9600;
    this.maxArduinoPingTime = 1500;
    this.readings = {}
    this.parameters = {}

    // this.expressApp = express();
    // this.httpServer = http.createServer(this.expressApp);

    this.client = new ClientMessager(this);
    // this.arduino = new ArduinoMessager(this);

    this.client.setupIO(this.port);
  }

  handleNewReadings(paramDict){
    this.client.handleNewReadings(paramDict);
  }

}


