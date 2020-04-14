import socketIOClient from "socket.io-client";

export default class Messager {
    constructor(port){
        this.socket = socketIOClient('http://localhost:' + port);
    }

	sendParametersToBackend(params){
        console.log("TEST")
        console.log(params)
		this.socket.emit('parameterChange', params)
	}

    dataListener(cb){
        this.socket.on('data', data => cb(data))
    }

    // sampleTidalVolumeDataListener(cb){
    //     setInterval(() => {
	// 		let val = Math.floor(4*Math.random() + 10) + 1;
	// 		cb({
	// 			type: 'tidal volume',
	// 			value: val
	// 		})
	// 	}, 1000)
    // }

    // samplePressureDataListener(cb) {
    //     setInterval(() => {
	// 		let val = Math.floor(3*Math.random() + 25 ) + 1;
	// 		cb({
	// 			type: 'pressure',
	// 			value: val
	// 		})
	// 	}, 2000)
    // }
    
}
