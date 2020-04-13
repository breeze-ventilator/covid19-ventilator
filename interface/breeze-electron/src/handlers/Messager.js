import socketIOClient from "socket.io-client";

export default class Messager {
    constructor(port){
        this.socket = socketIOClient('http://localhost:' + port);
    }

	sendParametersToBackend(params){
		this.socket.emit('parameterChange', params)
	}

    tidalVolumeListener(cb){
        this.socket.on('tidalVolume', tidalVolume => cb('tidalVolume', tidalVolume))
    }

    batteryVoltageListener(cb){
        this.socket.on('batteryVoltage', batteryVoltage => cb('batteryVoltage',batteryVoltage))
    }

    batteryPercentageListener(cb) {
			this.socket.on('batteryPercentage', batteryPercentage => cb('batteryPercentage', batteryPercentage))
    }

    errorListener(cb){
       this.socket.on('error', (errorCode, abPressure, abFiO2) => cb('error', errorCode, abPressure, abFiO2))
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
