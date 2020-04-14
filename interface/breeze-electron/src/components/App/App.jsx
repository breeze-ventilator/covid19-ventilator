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

    this.state = {
      currentlyAlarming: [],
      setup: true,
      data: {},
      parameters: {}
    }

    // Set default data values on state.
    for(const name of readingNames){
      this.state.data[name] = readingsInfo[name].default;
    }

    // Set default parameter values on state.
    for(const name in parameterInfo){
      this.state.parameters[name] = parameterInfo[name].default;
    }

    // Set default alarms on state.
    this.state.alarms = defaultAlarms;

    this.messager = new Messager(5000);

    /* TODO: uncommment datalistener and coment sample listener on release.abnormalFiO2 */
    // this.messager.dataListener(this.updateData.bind(this));
    this.messager.sampleDataListener(this.updateData.bind(this));

    this.setParameters = this.setParameters.bind(this);
    this.setAlarms = this.setAlarms.bind(this);
    this.setCurrentlyAlarming = this.setCurrentlyAlarming.bind(this);
    this.doneSetup = this.doneSetup.bind(this);
    this.sendToArduino = this.sendToArduino.bind(this);
  }

  setParameters(parameters){
    this.state.parameters = parameters;
    this.setState(this.state);
  }

  sendToArduino(){
    let toSend = {};

    // Get mode and all other parameters.
    toSend.mode = modes.indexOf(this.state.parameters.mode);
    for(param in allParams){
      toSend[param] = this.state.parameters[param];
    }

    // Post processing.
    toSend.apneaTime *= 10;
    toSend.riseTime *= 10;

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
    console.log("[App.jsx]: Data Received.")
    console.log(data)

    for(let i = 1; i < data.length; i++){
      this.state.data[readingNames[i]] = data[i];
    }


    if (this.isMount) {
      this.setState(this.state);
    }
  }

  doneSetup(){
    this.state.setup = false;
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
            setCurrentlyAlarming={this.setCurrentlyAlarming}
        />
        <Switch>
        <Route path="/diagnostics">
          <Vitals sendToArduino={this.sendToArduino} allData={this.state.data} allParameters={this.state.parameters} currentlyAlarming={this.state.currentlyAlarming} />
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
