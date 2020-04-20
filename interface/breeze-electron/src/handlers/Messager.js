const { ipcRenderer } = require('electron')

export default class Messager {
    constructor(){
			
    }

	sendParametersToBackend(params){
		console.log("Sending to backend... ")
		console.log(params)
		ipcRenderer.send('newParams', params)
	}

	dataListener(cb){
		ipcRenderer.on('newData', (event, arg) => {
			if (arg.type == "data") {
				cb(arg.data);
			}
			console.log(arg)
		})
	}
}