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
        tidalVolume: []
      }
    }
    this.messager = new Messager(this.updateData.bind(this));
  }

  componentDidMount(){
    this.isMount = true;
  }

  updateData(update) {
    if (update.type === 'tidal volume'){
      if (this.state.data.tidalVolume.length === this.numPoints){
        this.state.data.tidalVolume.shift();
      }
      this.state.data.tidalVolume.push(update.value);
    }

    if (this.isMount) {
      this.setState(this.state);
    }
  }

  render() {
    return (
      <div>

      {/* <Vitals timeSeriesData={this.state.data.tidalVolume} />
      <ValueChart
          progress={40}
          color="#3c71d0"
      /> */}
      <Router>
        <SimpleBottomNavigation />

        <Switch>
        <Route path="/settings">
          <Settings />
        </Route>
        <Route path="/diagnostics">
          <Vitals timeSeriesData={this.state.data.tidalVolume}/>
        </Route>
        <Route path="/alarms">
          <Alarms />
        </Route>
        </Switch>
      </Router>

      </div>
    );
  }
}
