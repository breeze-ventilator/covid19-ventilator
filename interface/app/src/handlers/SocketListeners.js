import socketIOClient from "socket.io-client";



export default class Listeners {
    constructor(port){
        this.socket = socketIOClient('http://localhost:' + port);
    }

    pressureListener(){

    }

    tidalVolumeListener(){

    }

    batteryVoltageListener(){

    }

    errorListener(){

    }

    
}