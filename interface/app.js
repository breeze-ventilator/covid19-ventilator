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