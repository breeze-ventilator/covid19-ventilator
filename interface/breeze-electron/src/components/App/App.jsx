import React from 'react';
import Messager from '../../handlers/Messager';
import {readingNames, readingsInfo, parameterInfo, defaultAlarms, modes, allParams} from '../../util/constants';

import './css/App.css';

import { HashRouter as Router, Switch, Route, Redirect } from 'react-router-dom';

import Vitals from '../Vitals/Vitals';
import Alarms from '../Alarms/Alarms';
import AlarmsHandler from '../Alarms/AlarmsHandler';
import StatusBar from '../StatusBar/StatusBar';


export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.isMount = false;
    
    let state = {
      currentlyAlarming: [],
      setup: true,
      data: {},
      parameters: {},
      tidalVolumeTimes: [],
      tidalVolumes: []
    }
    
    // Set default data values on state.
    for(const name of readingNames){
      state.data[name] = readingsInfo[name].default;
    }

    // Set default parameter values on state.
    for(const name in parameterInfo){
      state.parameters[name] = parameterInfo[name].default;
    }

    // Set default alarms on state.
    state.alarms = defaultAlarms;
    state.receivedAlarmFromArduino = false;
    state.arduinoAlarmType = null;

    this.state = state;

    // Note: Second parameter is whether to use sample listener.
    this.messager = new Messager(5000, false); 

    this.messager.dataListener(this.updateData.bind(this));

    this.setParameters = this.setParameters.bind(this);
    this.setAlarms = this.setAlarms.bind(this);
    this.setCurrentlyAlarming = this.setCurrentlyAlarming.bind(this);
    this.toggleSetup = this.toggleSetup.bind(this);
    this.sendToArduino = this.sendToArduino.bind(this);
  }

  setParameters(parameters){
    for(const paramName in this.state.parameters){
      this.state.parameters[paramName] = parameters[paramName];
    }
    this.setState(this.state);
    this.sendToArduino();
  }

  sendToArduino(){
    let toSend = {};

    // Get mode and all other parameters.
    toSend.mode = modes.indexOf(this.state.parameters.mode);
    for(let param of allParams){
      toSend[param] = this.state.parameters[param];
    }

    // Post processing.
    toSend.apneaTime *= 10;
    toSend.riseTime *= 10;
    toSend.sensitivity *= -1;

    // Alarms.
    toSend.highInspiratoryPressureAlarm = this.state.alarms.pressure.max;
    toSend.lowExpiratoryPressureAlarm = this.state.alarms.pressure.min;

    this.messager.sendParametersToBackend(toSend);
  }

  componentDidMount(){
    this.isMount = true;
  }

  setAlarms(alarms) {
    this.setState({alarms});
  }

  setCurrentlyAlarming(currentlyAlarming) {
    this.setState({currentlyAlarming});
  }

  updateData(data) {
    // console.log("[App.jsx]: Data Received.")
    // console.log(data)

    // Set first two parameters.
    this.state.data[readingNames[1]] = data[1];
    this.state.data[readingNames[2]] = data[2];

    // Only set tidal volume if breathCompleted. TODO: 
    let isBreathCompleted = data[2];
    if(isBreathCompleted == 1){
      this.state.data[readingNames[3]] = data[3];
      
      // Calculate tidalVolumes
      this.state.tidalVolumeTimes.push((new Date()).getTime());
      this.state.tidalVolumes.push(data[3]);
      
      let timeDifference =  this.state.tidalVolumeTimes[this.state.tidalVolumeTimes.length-1] - this.state.tidalVolumeTimes[0]
      const MILLISECONDS_IN_A_MINUTE = 60000;

      while(timeDifference >= MILLISECONDS_IN_A_MINUTE){
        this.state.tidalVolumeTimes.shift() // pops the first element
        this.state.tidalVolumes.shift();
        timeDifference = this.state.tidalVolumeTimes[this.state.tidalVolumeTimes.length-1] - this.state.tidalVolumeTimes[0]
      }

      // Calculate respiratory rate
      this.state.data.trueRespiratoryRate = this.state.tidalVolumeTimes.length;
      
      // Calculate minute ventilation
      if (this.state.tidalVolumes.length != 0) {
        let sumOfTidalVolumes = this.state.tidalVolumes.reduce((a,b) => a + b, 0)
        this.state.data.minuteVentilation = sumOfTidalVolumes;
      }
    }


    for(let i = 4; i < data.length; i++){
      this.state.data[readingNames[i]] = data[i];
    }

    /*
      SETS  
          state.receivedAlarmFromArduino;
          state.arduinoAlarmType;
          0 none, 1, low fio2, 2 high fio2
          depending on data from arduino
    */
    if(data[4] == 1){
      this.state.receivedAlarmFromArduino = true;
      this.state.arduinoAlarmType = "Low FiO2";
    }
    else if(data[4] == 2){
      this.state.receivedAlarmFromArduino = true;
      this.state.arduinoAlarmType = "High FiO2";   
    }
    else{
      this.state.receivedAlarmFromArduino = false;
      this.state.arduinoAlarmType = null;
    }

    if (this.isMount) {
      this.setState(this.state);
    }
  }

  toggleSetup(){
    this.state.setup = !this.state.setup;
    this.setState(this.state);
  }

  render() {
    return (
      <div>
      <Router>
        <StatusBar />
        <AlarmsHandler
            alarms={this.state.alarms}
            allData={this.state.data}
            allParameters={this.state.parameters}
            arduinoAlarmType={this.state.arduinoAlarmType}
            receivedAlarmFromArduino={this.state.receivedAlarmFromArduino}
            setCurrentlyAlarming={this.setCurrentlyAlarming}
        />
        <Switch>
        <Route path="/diagnostics">
          <Vitals toggleSetupHandler={this.toggleSetup} setup={this.state.setup} setParameters={this.setParameters} allData={this.state.data} allParameters={this.state.parameters} currentlyAlarming={this.state.currentlyAlarming} />
        </Route>
        <Route path="/alarms">
          <Alarms
            alarms={this.state.alarms}
            setAlarms={this.setAlarms}
          />
        </Route>
        </Switch>
        <Redirect from="" to="/diagnostics" />
        <Redirect from="/" to="/diagnostics" />
      </Router>
        <div className="battery">
          <div className="battery-level" style={{height : this.state.data.batteryPercentage + readingsInfo.batteryPercentage.unit}}></div>
        </div>
      </div>
    );
  }
}
