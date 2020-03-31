import React from 'react';
import Messager from '../../handlers/Messager';

import d3Config from '../LineChart/scripts/d3Config.js'
import './css/App.css';

import { BrowserRouter as Router, Switch, Route, Redirect } from 'react-router-dom';

import Vitals from '../Vitals/Vitals';
import Settings from '../Settings/Settings';
import Alarms from '../Alarms/Alarms';
import SimpleBottomNavigation from '../SimpleBottomNavigation/SimpleBottomNavigation';

export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.numPoints = d3Config.numDataPoints;
    this.isMount = false;
    this.state = {
      data: {
        tidalVolume: 5,
        pressure: 5
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
      }
    }
    this.messager = new Messager(5000);

    this.messager.sampleTidalVolumeDataListener(this.updateData.bind(this));
    this.messager.samplePressureDataListener(this.updateData.bind(this));

    this.setParameters = this.setParameters.bind(this);

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
    }
    if(update.type === 'pressure'){
      this.state.data.pressure = update.value;
    }

    if (this.isMount) {
      this.setState(this.state);
    }
  }

  render() {
    return (
      <div>
      <Router>
        <SimpleBottomNavigation />
        <Switch>
        <Route path="/settings">
          <Settings allParameters={this.state.parameters} setParameters={this.setParameters}/>
        </Route>
        <Route path="/diagnostics">
          <Vitals allData={this.state.data}/>
        </Route>
        <Route path="/alarms">
          <Alarms allData={this.state.data} />
        </Route>
        </Switch>
        <Redirect from="/" to="settings" />
      </Router>
      <div class="battery">
          <div class="battery-level" style={{height : "75%"}}></div>
        </div>
      </div>
    );
  }
}
