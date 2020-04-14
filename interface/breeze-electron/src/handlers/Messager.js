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
	
    sampleDataListener(cb){
		// Creates sample data similar to arduino.
		// Note/TODO: Change ranges to reflect real ranges or whatever you are testing.
		let data_names = [ 
			"checkSum",
			"batteryPercentage",
			"breathCompleted",
			"tidalVolume", 
			"errorCode",
			"abnormalPressure", 
			"abnormalFiO2"
		]
		let ranges = [
			[0,0], // Check sum
			[0,100], // Battery percent
			[0,1], // Breath completed
			[5,8], // Tidal volume
			[0,0], // Error code
			[0,0], // Abnormal pressure
			[21,92] // Abnormal fio2
		]

		// Interval 100 ms.
        setInterval(() => {
			let data = []
			for(let i = 0; i < data_names.length; i++){
				data.push(Math.floor(Math.random() * (ranges[i][1] - ranges[i][0] + 1)) + ranges[i][0]);
			}
			cb(data);
		}, 100)

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
