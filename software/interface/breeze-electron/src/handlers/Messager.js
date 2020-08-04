import {readingNames, readingsInfo} from '../util/constants';
const electron = window.require('electron')
const ipcRenderer = electron.ipcRenderer;
const testing = false // change to true for testing

export default class Messager {
    constructor(){
    }

	sendParametersToBackend(params){
		console.log("Sending to backend... ")
		console.log(params)
		ipcRenderer.send('newParams', params)
	}

	dataListener(cb){
		if (testing){
			this.sampleDataListener(cb)
		} else {
			ipcRenderer.on('newData', (event, arg) => {
				if (arg.type == "data") {
					cb(arg.data);
				}
				console.log(arg)
			})
		}
	}

	sampleDataListener(cb){
		setInterval(() => {
			const data = [];
			for(const name of readingNames){
				data.push(Math.floor(Math.random() * (readingsInfo[name].alarmMax - readingsInfo[name].alarmMin + 1)) + readingsInfo[name].alarmMin);
			}
			console.log(data);
			cb(data);
		}, 3000)
	}
}