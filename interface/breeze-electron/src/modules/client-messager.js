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

		socket.on('parameterChange', (newParameters) => this.top.handleNewParameters(newParameters));
		socket.on('disconnect', () => this.handleDisconnect());
	}
	
	handleDisconnect() {
		console.log('user disconnected');
	}

	/* Handlers from Arduino Data */
	handleNewReadings(pressure, tidalVolume, batteryPercentage, breathCompleted, error){
		if(error != 0){
			handleError(error);
		}
		handlePressure(pressure);
		handleBatteryPercentage(batteryPercentage);
		handleBreathCompleted(breathCompleted, tidalVolume); // Sends tidal volume if breath complete = 1;
	}

	// tidalVolume = {time: DateTime, volume: volume}
	// TODO: Aggregate values depending on freq., for frontend ?
	handlePressure(pressure){
		socket.emit('pressure', { pressure: pressure });
	}

	handleBreathCompleted(breathCompleted, tidalVolume){
		if(breathCompleted == 1){
			socket.emit('tidalVolume', { tidalVolume: tidalVolume });
		}
	}

	handleBatteryPercentage(batteryPercentage){
		socket.emit('batteryPercentage', { batteryPercentage: batteryPercentage});
	}
	
	handleError(error){
		// Depending on error, either send to frontend or nothing.
	}

	sendToClient(message) {
		this.io.emit(message);
	}
}