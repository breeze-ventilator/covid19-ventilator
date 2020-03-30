import socketIOClient from "socket.io-client";

export default class Messager {
    constructor(port){
        this.socket = socketIOClient('http://localhost:' + port);
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
			let val = Math.random()*10.0 - 5.0;
			cb({
				type: 'tidal volume',
				value: val
			})
		}, 1000/60)
    }

    
}