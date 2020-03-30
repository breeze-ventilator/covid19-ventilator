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

		let bufferData = Buffer.from(data, 'utf8');
		
		let checkSum = bufferData.readInt8(0);
		let pressure = bufferData.readInt16BE(1);
		let flow = bufferData.readInt16BE(3);
		let batteryVoltage = bufferData.readInt8(5);
		let error = bufferData.readInt8(6);

		testSum = pressure;
		testSum ^= flow;
		testSum ^= batteryVoltage;
		testSum ^= error;

		if(testSum === checkSum){
			this.top.handleNewReadings(pressure, flow, batteryVoltage, error);
		}
		// Otherwise, should just wait for the next reading.
	}

	// TODO !
	handleNewParameters(newParameters){

	}

	// TODO !
	handleArduinoTimeout(){

	}
}