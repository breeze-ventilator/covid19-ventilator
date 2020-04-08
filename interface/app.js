/*

1) Communicates with Arduino via Serial (arduinoer)

2) Information for frontend
  - Data (Sensors (Arduino))
    --> Sockets

client (frontend):
  

top
  arduinoer: communicates with arduino
    serial
  frontender: communicates with frontend

*/
const Top = require('./top.js');
const top = new Top();
const { app, BrowserWindow } = require('electron');

function createWindow() {
  const win = new BrowserWindow({
    width: 480,
    height: 800,
    webPreferences: {
      nodeIntegration: true
    }
  })
  
  win.loadURL("http://localhost:3000/setup")
}

app.on("ready", createWindow)
