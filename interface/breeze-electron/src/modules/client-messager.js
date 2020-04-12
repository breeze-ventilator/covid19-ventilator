const io = require('socket.io');

module.exports = class ClientMessager {
	constructor(top) {
		this.top = top;
		this.io = io(this.top.httpServer, { serveClient: false });
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
	handleNewReadings(paramDict){
		if(paramDict["error code"] != 0){
			handleError(paramDict["error code"], paramDict["abnormal pressure"], paramDict["abnormal FiO2"]);
		}
		handleBatteryPercentage(paramDict["battery percentage"]);
		handleBreathCompleted(paramDict["breath complete"], paramDict["tidal volume"]); // Sends tidal volume if breath complete = 1;
	}

	// tidalVolume = {time: DateTime, volume: volume}
	// TODO: Aggregate values depending on freq., for frontend ?
	handleBreathCompleted(breathCompleted, tidalVolume){
		if(breathCompleted == 1){
			socket.emit('tidalVolume', { tidalVolume: tidalVolume });
		}
	}

	handleBatteryPercentage(batteryPercentage){
		socket.emit('batteryPercentage', { batteryPercentage: batteryPercentage});
	}
	
	handleError(errorCode, abnormalPressure, abnormalFiO2){
		socket.emit('error', {errorCode:errorCode, abnormalPressure:abnormalPressure, abnormalFiO2:abnormalFiO2})
	}

	sendToClient(message) {
		this.io.emit(message);
	}
}
