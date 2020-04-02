import socketIOClient from "socket.io-client";

export default class Messager {
    constructor(port){
        this.socket = socketIOClient('http://localhost:' + port);
    }

	sendParametersToBackend(params){
		this.socket.emit('parameterChange', params)
	}

    pressureListener(cb){
        this.socket.on('pressure', pressure => cb(pressure))
    }

    tidalVolumeListener(cb){
        this.socket.on('tidalVolume', tidalVolume => cb(tidalVolume))
    }

    batteryVoltageListener(cb){
        this.socket.on('batteryVoltage', batteryVoltage => cb(batteryVoltage))
    }

    errorListener(cb){
        // TODO: Finish error listeners for specific errors.
    }

    sampleTidalVolumeDataListener(cb){
        setInterval(() => {
			let val = Math.floor(4*Math.random() + 10) + 1;
			cb({
				type: 'tidal volume',
				value: val
			})
		}, 1000)
    }

    samplePressureDataListener(cb) {
        setInterval(() => {
			let val = Math.floor(3*Math.random() + 25 ) + 1;
			cb({
				type: 'pressure',
				value: val
			})
		}, 2000)
    }
    
}