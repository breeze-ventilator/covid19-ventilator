const SerialPort = require('serialport');
const ByteLength = require('@serialport/parser-byte-length')

const LENGTH_OF_PARAMETER_MESSAGE = 15;

module.exports = class ArduinoMessager {
	constructor(top) {
		this.top = top;
		this.port = new SerialPort(this.top.serialPort, {baudRate: this.top.baudRate});		
		this.parser = this.port.pipe(new ByteLength({length: 1})); // breaks messages by 1 byte length
		this.connected = false;
		this.timeSinceLastArduinoMessage = new Date();
		this.toSend = {}
		this.readingMapping = ["checksum", "battery percentage", "breath complete", "tidal volume", "error code", "abnormal pressure", "abnormal FiO2"]
		this.readingCount = 0;
		this.newParametersBuffer = undefined;
		this.modes = ["Standby", "Pressure Control", "Pressure Support"]

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
		console.log('[Arduino Messager]: Received the following data:', data.readUInt8());

		if(!this.connected){
			this.handshakeWithArduino(data);
			this.timeSinceLastArduinoMessage = new Date();
		}
		else {
			this.parseArduinoReadings(data);

			if (this.newParametersBuffer && this.readingCount == 0) { // data reading finished
				this.port.write(this.newParametersBuffer);
				this.newParametersBuffer = undefined;
			}
		}
	}

	handshakeWithArduino(data){
		if (data.readUInt8() == 1){
			this.port.write('elbowbump\n');
			this.connected = true;
		}
	}

	parseArduinoReadings(data){
		// TODO: Add breath time parsing.
		if (this.isArduinoTimedOut()) {
			this.handleArduinoTimeout();
		}

		let key = this.readingMapping[this.readingCount]
		this.toSend[key] = data.readUInt8()

		console.log(key, this.toSend[key])
		
		// reading count of 5 means all readings have been added to the dict
		if (this.readingCount == this.readingMapping.length-1){
			this.top.handleNewReadings(this.toSend)
			this.readingCount = 0;
		} else {
			this.readingCount++;
		}
	}

	// TODO !
	handleNewParameters(newParameters) {
		console.log(newParameters);
		
		this.newParametersBuffer = this.loadParametersIntoBuffer(newParameters);
	}

	loadParametersIntoBuffer(newParameters) {
		/*
		Mode (0,1,2)
		FiO2, in % O2
		PEEP, in cm H2O
		Inspiratory pressure (∆P), in cm H2O
		Sensitivity, in L/min
		Rate if pressure control, breaths per minute
		Inspiratory time percentage if pressure control
		Flow cycling off % if pressure support
		Apnea time if pressure support, in tenth of second
		Rise time, in tenth of second  (default value to 1)
		High inspiratory pressure alarm, in cm H2O
		Low expiratory pressure alarm, in cm H2O
		*/

		let buffer = Buffer.alloc(LENGTH_OF_PARAMETER_MESSAGE);
		buffer.write('P', 1);
		
		let checksum = 0;
		buffer.writeUInt8(checksum, 1); // offset of 1

		buffer.writeUInt8(this.modes.indexOf(newParameters.mode), 2);
		buffer.writeUInt8(newParameters.fiO2, 3);
		// buf.writeUInt8(newParameters.inspiratoryPressure, 4);
		// buf.writeUInt8(newParameters.respiratory, 5);
		return buffer;
	}

	// TODO !
	handleArduinoTimeout(){

	}
}