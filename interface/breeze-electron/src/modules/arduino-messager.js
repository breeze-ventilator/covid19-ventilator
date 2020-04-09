const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

module.exports = class ArduinoMessager {
	constructor(top) {
		this.top = top;
		this.port = new SerialPort(this.top.serialPort, {baudRate: this.top.baudRate});		
		this.parser = this.port.pipe(new Readline({delimeter: '\n'})); // breaks messages by newline
		this.connected = false;
		this.timeSinceLastArduinoMessage = new Date();

		this.port.on('open', () => this.handlePortOpen());
		this.port.on('close', () => this.handlePortClose());

		this.parser.on('data', (data) => this.handleData(data));
	}

	isArduinoTimedOut(){
		if(this.connected){
			if(new Date().getTime() - this.timeSinceLastArduinoMessage.getTime() > this.maxArduinoPingTime){
				return true;
			}
		}
		this.timeSinceLastArduinoMessage = new Date();
		return false;
	}

	handlePortOpen() {
		console.log('[Arduino Messager]: Serial port is now open.');
		// Need to handshake again if just opened.
		this.connected = false;
	}

	handlePortClose() {
		console.log('[Arduino Messager]: Serial port is now closed.');
		// Sound the alarm?!?
	}

	handleData(data) {
		console.log('[Arduino Messager]: Received the following data:', data);

		if(!this.connected){
			handshakeWithArduino(data);
			this.timeSinceLastArduinoMessage = new Date();
		}
		
		if(this.connected){
			parseArduinoReadings(data);
		}
	}

	handshakeWithArduino(data){
		if(data.equals('elbowbump')){
			port.write('elbowbump\n')
			this.connected = true;
		}
	}

	parseArduinoReadings(data){
		// TODO: Add breath time parsing.
		if(isArduinoTimedOut()){
			this.handleArduinoTimeout();
		}

		let flowBuffer = Buffer.from(data.slice(4,6))

		let checkSum = data.charChodeAt(0);
		let pressure = data.charChodeAt(1);
		let batteryPercentage = data.charChodeAt(2);
		let breathCompleted = data.charChodeAt(3);
		let tidalVolume = flowBuffer.readInt16BE(0);
		let error = data.charChodeAt(6);

		// NO CHECKSUM
		this.top.handleNewReadings(pressure, tidalVolume, batteryPercentage, breathCompleted, error);
	}

	// TODO !
	handleNewParameters(newParameters){

	}

	// TODO !
	handleArduinoTimeout(){

	}
}