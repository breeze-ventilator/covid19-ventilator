const SerialPort = require('serialport');
const ByteLength = require('@serialport/parser-byte-length')

export default class ArduinoMessager {
	constructor(top) {
		this.top = top;
		this.port = new SerialPort(this.top.serialPort, {baudRate: this.top.baudRate});		
		this.parser = this.port.pipe(new ByteLength({length: 1})); // breaks messages by 1 byte length
		this.connected = false;
		this.timeSinceLastArduinoMessage = new Date();
		this.toSend = {}
		this.paramMapping = ["checksum", "battery percentage", "breath complete", "tidal volume", "error code", "error code addendum"]
		this.paramCount = 0;

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

		let key = this.paramMapping[this.paramCount]
		this.toSend[key] = data.readUInt8()

		console.log(key, this.toSend[key])

		if (this.paramCount == 5){
			this.top.handleNewReadings(this.toSend)
		}

		this.paramCount += 1;
	}

	// TODO !
	handleNewParameters(newParameters){
		let buf = Buffer.alloc(15);
		let modes = ["Pressure Control", "Pressure Support", "Standby"]

		// P and checksum
		buf.write('P', 0, 1)
		buf.writeInt8(0, 1)

		let bufOffset = 2;
		for (let key in newParameters.keys()) {
			if(key == "mode") {
				buf.writeInt8(modes.indexOf(newParameters[key]), bufOffset)
			}
			else{
				buf.writeInt8(newParameters[key], bufOffset)
			}
			bufOffset += 1;
		}

		buf.write('\n', bufOffset, 1);
		this.port.write(buf)
	}

	// TODO !
	handleArduinoTimeout(){

	}
}