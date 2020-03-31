import React from 'react';
import ValueCard from '../Card/Card';
import Grid from "@material-ui/core/Grid";
import './css/vitals.css'

export default class Vitals extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      data: {
        tidalVolume: 5,
        pressure: 5
      }
    }
  }

  componentDidUpdate(prevProps){
    const { allData } = this.props;
    this.state.data = allData
    if (this.isMount) {
      this.setState(this.state);
    }
  }

  render() {
    return (
      <div className="mainContainer">
        <Grid
          container
          direction="row"
          justify="space-around"
          alignItems="center"
        >

          <ValueCard value={this.state.data.tidalVolume} unit='mL' name='Tidal Volume'/>
          <ValueCard value={this.state.data.pressure} unit='kPa' name='Pressure'/>
        </Grid>

      </div>
      // <LineChart timeSeriesData={this.props.timeSeriesData} />
    );
  }
}
