const SerialPort = require('serialport');
const ByteLength = require('@serialport/parser-byte-length')

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
		this.numParameters = 15;
		this.newParameters = undefined;
		this.modes = ["Pressure Control", "Pressure Support", "Standby"]

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
			if(this.newParameters) {
				this.port.write(this.newParameters)
			}
		}
	}

	handshakeWithArduino(data){
		if(data.readUInt8() == 1){
			this.port.write('elbowbump\n')
			this.connected = true;
		}
	}

	parseArduinoReadings(data){
		// TODO: Add breath time parsing.
		if(this.isArduinoTimedOut()){
			this.handleArduinoTimeout();
		}

		let key = this.readingMapping[this.readingCount]
		this.toSend[key] = data.readUInt8()

		console.log(key, this.toSend[key])

		this.readingCount++;
		
		// reading count of 5 means all readings have been added to the dict
		if (this.readingCount == this.readingMapping.length-1){
			this.top.handleNewReadings(this.toSend)
			this.readingCount = 0;
		}
	}

	// TODO !
	handleNewParameters(newParameters) {
		if (this.connected) {
			let buf = Buffer.alloc(this.numParameters);

			// push "P" and checksum params to buffer
			buf.write('P', 0, 1) // offset 0, length 1
			buf.writeUInt8(0, 1) // write the number 0, offset 1

			// buffer offset of 2 for the 2 params already written
			let bufOffset = 2;
			for (let key in newParameters.keys()) {
				if(key == "mode") {
					// change from string to 1,2,3 depending on mode
					buf.writeUInt8(this.modes.indexOf(newParameters[key]) + 1, bufOffset)
				}
				else {
					buf.writeUInt8(newParameters[key], bufOffset)
				}
				bufOffset++;
			}

		// lastly, write the new line charcter
		buf.write('\n', bufOffset, 1);

		this.newParameters = buf;
		}
	}

	// TODO !
	handleArduinoTimeout(){

	}
}