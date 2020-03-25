const path = require('path');
const express = require('express');
const http = require('http');

const ArduinoMessager = require('./modules/arduino-messager.js');
const ClientMessager = require('./modules/client-messager.js');

module.exports = class Top {
  constructor() {
    // TODO: move to config file
    this.port = 3000;
    this.serialPort = '/dev/ttyACM0';
    this.baudRate = 9600;
    
    this.expressApp = express();
    this.httpServer = http.createServer(this.expressApp);

    this.setupExpressApp();
    this.setupHttpServer();

    this.arduino = new ArduinoMessager(this);
    this.client = new ClientMessager(this);

    this.client.setupIO();
  }

  setupExpressApp() {
    // if we can load '/', we know that server is running
    this.expressApp.get('/', (req, res) => {
      res.send({response: "Running express app."}).status(200);
    });
  }

  setupHttpServer() {
    this.httpServer.listen(this.port, () => {
      console.log('Listening on port', this.port);
    })
  }

}


