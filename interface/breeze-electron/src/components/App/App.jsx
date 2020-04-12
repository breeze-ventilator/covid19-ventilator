import React from 'react';
import Messager from '../../handlers/Messager';

import d3Config from '../LineChart/scripts/d3Config.js'
import './css/App.css';

import { HashRouter as Router, Switch, Route, Redirect } from 'react-router-dom';

import Vitals from '../Vitals/Vitals';
import Alarms from '../Alarms/Alarms';
import AlarmsHandler from '../Alarms/AlarmsHandler';
import SimpleBottomNavigation from '../SimpleBottomNavigation/SimpleBottomNavigation';

export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.numPoints = d3Config.numDataPoints;
    this.isMount = false;
    this.state = {
      data: {
        tidalVolume: 5,
        pressure: 5, 
        batteryPercentage:"75%"
      },
      parameters: {
        mode: "Pressure Control", // one of Pressure Control, Pressure Support, Standby
        fiO2: 80, // Control + Support
        peep: 20, // Control + Support
        peakPressure: 20, // Control + Support
        sensitivity: 80, // Support
        respiratoryRate: 0, // Control
        inspiratoryTime: 0, // Control
        flow: 0, //Support
        apneaTime: 20, // Support
        riseTime: 0,
        highInspAlarm:0,
        lowExpAlarm:0
      },
      alarms: {
        minuteVentilation: {
          min: 6,
          max: 10
        },
        pressure: {
          min: 0,
          max: 35
        }
      },
      currentlyAlarming: [],
      setup: true
    }
    this.messager = new Messager(5000);

    this.messager.tidalVolumeListener(this.updateData.bind(this));
    this.messager.batteryPercentageListener(this.updateData.bind(this));

    this.setParameters = this.setParameters.bind(this);
    this.setAlarms = this.setAlarms.bind(this);
    this.setCurrentlyAlarming = this.setCurrentlyAlarming.bind(this);
    this.doneSetup = this.doneSetup.bind(this);
    this.messager.sendParametersToBackend(this.state.parameters);
  }

  setParameters(parameters){
    this.state.parameters = parameters;
    this.setState(this.state);
    console.log("IN APP: ")
    console.log(this.state)

    // TODO: SHIP with messager to arduino! 
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

  updateData(type, value) {
    if (type === 'tidal volume'){
      this.state.data.tidalVolume = value;
    }
    if(type === 'batteryPercentage'){
      this.state.data.batteryPercentage = value.toString() + "%";
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
        <SimpleBottomNavigation setup={false} />
        <AlarmsHandler
            alarms={this.state.alarms}
            allData={this.state.data}
            allParameters={this.state.parameters}
            setCurrentlyAlarming={this.setCurrentlyAlarming}
        />
        <Switch>
        <Route path="/diagnostics">
          <Vitals allData={this.state.data} allParameters={this.state.parameters} currentlyAlarming={this.state.currentlyAlarming} />
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
          <div className="battery-level" style={{height : this.state.data.batteryPercentage}}></div>
        </div>
      </div>
    );
  }
}
