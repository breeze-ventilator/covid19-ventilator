const SerialPort = require('serialport');
const ByteLength = require('@serialport/parser-byte-length')

module.exports = class ArduinoMessager {
	constructor(top) {
		this.top = top;
		this.port = new SerialPort(this.top.serialPort, {baudRate: this.top.baudRate});		
		this.parser = this.port.pipe(new ByteLength({length: 2})); // breaks messages by 2 byte length
		this.connected = false;
		this.timeSinceLastArduinoMessage = new Date();
		this.toSend = []

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
		if(data.readUInt16BE() == 1){
			port.write('elbowbump\n')
			this.connected = true;
		}
	}

	parseArduinoReadings(data){
		// TODO: Add breath time parsing.
		if(isArduinoTimedOut()){
			this.handleArduinoTimeout();
		}

		this.toSend.append(data.readUInt16BE())
		console.log(data.readUInt16BE())

		if(this.toSend.length == 6){
			this.top.handleNewReadings(this.toSend)
		}
	}

	// TODO !
	handleNewParameters(newParameters){

	}

	// TODO !
	handleArduinoTimeout(){

	}
}