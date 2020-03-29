import React from 'react';
import Vitals from '../Vitals/Vitals';
import ValueChart from '../ValueChart/ValueChart';
import SimpleBottomNavigation from '../SimpleBottomNavigation/SimpleBottomNavigation';
import Messager from '../../handlers/Messager';
import d3Config from '../LineChart/scripts/d3Config.js'
import './css/App.css';

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
      <Vitals timeSeriesData={this.state.data.tidalVolume} />
      <ValueChart
          progress={40}
          color="#3c71d0"
      />
      <SimpleBottomNavigation />
      </div>
    );
  }
}
