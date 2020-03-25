const io = require('socket.io');

module.exports = class ClientMessager {
	constructor(top) {
		this.top = top;
		this.io = io(this.top.httpServer);
	}
 
	setupIO() {
		this.io.on('connection', socket => this.handleSocketIOConnection(socket));
    }
    
	handleSocketIOConnection(socket){
		console.log('Client connected');

		socket.on('parameter-change', (newParameters) => this.handleParameterChange(newParameters)); // should we be using socketio or routes here?
		socket.on('disconnect', () => this.handleDisconnect());
	}

	handleParameterChange(newParameters){
		// ship the new parameters to the arduino
	}
	
	handleDisconnect() {
		console.log('user disconnected');
	}

	/* Handlers from Arduino Data */
	
	// tidalVolume = {time: DateTime, volume: volume}
	// TODO: Aggregate values depending on freq., for frontend
	handleTidalVolumeData(tidalVolume) {
		this.io.emit(tidalVolume);
	}

	handleFiO2Data(fiO2) {
		this.io.emit(fiO2);
	}

	handleMinuteVentilationData(minuteVentilation) {
		this.io.emit(minuteVentilation);
  }
}