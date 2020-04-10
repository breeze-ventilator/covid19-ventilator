import React from 'react';
import Messager from '../../handlers/Messager';

import d3Config from '../LineChart/scripts/d3Config.js'
import './css/App.css';

import { HashRouter as Router, Switch, Route, Redirect } from 'react-router-dom';

import Vitals from '../Vitals/Vitals';
import Alarms from '../Alarms/Alarms';
import SimpleBottomNavigation from '../SimpleBottomNavigation/SimpleBottomNavigation';

export default class App extends React.Component {
  constructor(props) {
    super(props);

    this.graphSettings = {
      numTidalVolumePoints: 100,
      numPressurePoints: 50,
    }

    this.isMount = false;
    this.state = {
      data: {
        tidalVolume: 10,
        pressure: 5,
      },
      series: {
        tidalVolume: [],
        pressure: []
      },
      parameters: {
        isPressureControlState: true,
        fiO2: 80, // Control + Support
        peep: 20, // Control + Support
        peakPressure: 20, // Control + Support
        sensitivity: 80, // Support
        apneaTime: 20, // Support
        inspiratoryTime: 0, // Control
        respiratoryRate: 0 // Control
      },
      setup: true
    }
    this.messager = new Messager(5000);

    this.messager.sampleTidalVolumeDataListener(this.updateData.bind(this));
    this.messager.samplePressureDataListener(this.updateData.bind(this));

    this.setParameters = this.setParameters.bind(this);
    this.doneSetup = this.doneSetup.bind(this);
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

  updateData(update) {
    if (update.type === 'tidal volume'){
      this.state.data.tidalVolume = update.value;
      if (this.state.series.tidalVolume.length === this.graphSettings.numTidalVolumePoints){
        this.state.series.tidalVolume.shift();
      }
      this.state.series.tidalVolume.push(update.value);
    }
    else if(update.type === 'pressure'){
      this.state.data.pressure = update.value;

      if (this.state.series.pressure.length === this.graphSettings.numPressurePoints){
        this.state.series.pressure.shift();
      }
      this.state.series.pressure.push(update.value);

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
        <Switch>
        <Route path="/diagnostics">
          <Vitals timeSeriesData={this.state.series} allData={this.state.data} allParameters={this.state.parameters} graphSettings={this.graphSettings}/>
        </Route>
        <Route path="/alarms">
          <Alarms allData={this.state.data} />
        </Route>
        </Switch>
        <Redirect from="" to="/diagnostics" />
        <Redirect from="/" to="/diagnostics" />
      </Router>
        <div className="battery">
          <div className="battery-level" style={{height : "75%"}}></div>
        </div>
      </div>
    );
  }
}
