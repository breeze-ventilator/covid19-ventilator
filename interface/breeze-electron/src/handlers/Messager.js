import socketIOClient from "socket.io-client";
import {readingNames, readingsInfo} from '../util/constants';

export default class Messager {
    constructor(port, useSampleListener=false){
		this.useSampleListener = useSampleListener;
		this.socket = null;
		if(!useSampleListener){
			this.socket = socketIOClient('http://localhost:' + port);
		}
    }

	sendParametersToBackend(params){
        console.log("Sending to backend... ")
        console.log(params)
		this.socket.emit('parameterChange', params)
	}

    dataListener(cb){
		if(this.useSampleListener){
			this.sampleDataListener(cb);
		}
		else{
			this.socket.on('data', data => cb(data))
		}
	}
	
    sampleDataListener(cb){
		// Creates sample data similar to arduino.
		// Based on constants file, alarmMin and alarmMax.

		// Interval 100 ms.
        setInterval(() => {
			let data = []
			for(const name of readingNames){
				data.push(Math.floor(Math.random() * (readingsInfo[name].alarmMax - readingsInfo[name].alarmMin + 1)) + readingsInfo[name].alarmMin);
			}
			cb(data);
		}, 1000)
	}
    
}
