import React from 'react';
import Messager from '../../handlers/Messager';

import d3Config from '../LineChart/scripts/d3Config.js'
import './css/App.css';

import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';

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
        fiO2: 80,
        peep: 20,
        sensitivity: 0,
        inspiratoryTime: 10,
        pressureSupportPoint: 20
      }
    }
    this.messager = new Messager(5000);

    this.messager.sampleTidalVolumeDataListener(this.updateData.bind(this));
    this.messager.samplePressureDataListener(this.updateData.bind(this));

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
          <Settings allParameters={this.state.parameters}/>
        </Route>
        <Route path="/diagnostics">
          <Vitals allData={this.state.data}/>
        </Route>
        <Route path="/alarms">
          <Alarms allData={this.state.data} />
        </Route>
        </Switch>
      </Router>

      </div>
    );
  }
}
