const io = require('socket.io');

module.exports = class ClientMessager {
	constructor(top) {
		this.top = top;
		this.io = io(this.top.httpServer);
	}
 
	setupIO(port) {
		this.io.on('connection', socket => this.handleSocketIOConnection(socket));
		this.io.listen(port);
    }
    
	handleSocketIOConnection(socket){
		console.log('Client connected');

		socket.on('parameter-change', (newParameters) => this.top.handleNewParameters(newParameters)); // should we be using socketio or routes here?
		socket.on('disconnect', () => this.handleDisconnect());
	}
	
	handleDisconnect() {
		console.log('user disconnected');
	}

	/* Handlers from Arduino Data */
	handleNewReadings(pressure, flow, batteryVoltage, error){
		if(error != 0){
			handleError(error);
		}
		handlePressure(pressure);
		handleFlow(flow);
		handleBatteryVoltage(batteryVoltage);
	}

	// tidalVolume = {time: DateTime, volume: volume}
	// TODO: Aggregate values depending on freq., for frontend ?
	handlePressure(pressure){
		socket.emit('pressure', { pressure: pressure });
	}

	handleFlow(flow){
		socket.emit('flow', { flow: flow });
	}

	handleBatteryVoltage(batteryVoltage){
		socket.emit('batteryVoltage', { batteryVoltage: batteryVoltage});
	}
	
	handleError(error){
		// Depending on error, either send to frontend or nothing.
	}

	sendToClient(message) {
		this.io.emit(message);
	}
}