import React from 'react';
import FlexValueCard from '../Card/FlexValueCard';
import Grid from "@material-ui/core/Grid";
import './css/vitals.css'
import Typography from '@material-ui/core/Typography';
import Button from '@material-ui/core/Button';

export default class Vitals extends React.Component {
  constructor(props) {
    console.log("diagnostics")
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
    let footer;
    if (this.props.allParameters.isPressureControlState) {
      footer = ( 
      <Grid container className="bottom">
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard value="ON" unit=" " prominence="h2" name="Pressure Control" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="80" unit="%" prominence="h2" name="FiO2" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="12" unit="" prominence="h2" name="Respiratory Rate" />
            </Grid>
          </Grid>
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard value="5" unit="cm H2O" prominence="h2" name="PEEP" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="1.0" unit="s" prominence="h2" name="Inspiratory Time" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="20" unit="cm H2O" prominence="h2" name="Peak Pressure" />
            </Grid>
          </Grid>
        </Grid>);
    } else {
      footer = (
        <Grid container className="bottom">
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard value="ON" unit=" " prominence="h2" name="Pressure Support" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="80" unit="%" prominence="h2" name="FiO2" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value={this.props.allParameters.sensitivity} unit="" prominence="h2" name="Sensitivity" />
            </Grid>
          </Grid>
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard value="5" unit="cm H2O" prominence="h2" name="PEEP" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="1.0" unit="s" prominence="h2" name="Apnea Time" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="20" unit="cm H2O" prominence="h2" name="Peak Pressure" />
            </Grid>
          </Grid>
        </Grid>
      )};
 
    return (
      <div className="mainContainer">
        {/* Header Observables */}
        <Grid container direction="row">
          <Grid item xs={6}>
              <FlexValueCard value={this.state.data.tidalVolume} unit='mL' prominence="h1" name='Tidal Volume'/>
          </Grid>
          <Grid item xs={6}>
              <FlexValueCard value={this.state.data.pressure} prominence="h1" unit='kPa' name='Pressure'/>
          </Grid>
        </Grid>

        {/* TODO: Graphs go here */} 
        {/* <LineChart timeSeriesData={this.props.timeSeriesData} /> */}

        {/* Footer modifiables */}
        { footer }
     </div>
    )};
}
