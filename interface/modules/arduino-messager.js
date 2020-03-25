const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

module.exports = class ArduinoMessager {
	constructor(top) {
		this.top = top;
		this.port = new SerialPort(this.top.serialPort, {baudRate: this.top.baudRate});		
		this.parser = this.port.pipe(new Readline({delimeter: '\n'})); // breaks messages by newline

		this.port.on('open', () => this.handlePortOpen());
		this.parser.on('data', (data) => this.handleData(data));
	}

	handlePortOpen() {
		console.log('serial port open');
	}

	handleData(data) {
		console.log('received data', data);
	}

}