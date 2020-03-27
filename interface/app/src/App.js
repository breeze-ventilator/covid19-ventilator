import React from 'react';
import LineChart from './LineChart';
import Messager from './Messager';
import './App.css';

export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.numPoints = 500;
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
      <LineChart timeSeriesData={this.state.data.tidalVolume} />
    );
  }
}
