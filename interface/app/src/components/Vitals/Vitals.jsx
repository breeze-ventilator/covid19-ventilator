import React from 'react';
import ValueCard from '../Card/Card';
import FlexValueCard from '../Card/FlexValueCard';
import Grid from "@material-ui/core/Grid";
import './css/vitals.css'
import SmallValueCard from '../Card/SmallerValueCard';
import Typography from '@material-ui/core/Typography';
import Button from '@material-ui/core/Button';

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
        
        {/* Footer modifiables */}
        <Grid container className="bottom">
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard value="ON" unit=" " prominence="h2" name="Pressure Control" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="80" unit="%" prominence="h2" name="FiO2" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard value="12" unit="rpm" prominence="h2" name="Respiratory Rate" />
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
        </Grid>
      </div>
    )}
}
/*


        <Grid
          container
          direction="row"
          alignItems="center"
          justify="center"
        >
          <Grid item direction="column" spacing={1} justify="space-around" alignItems="center">

          <Grid item>

          {this.props.allParameters.isPressureControlState
            &&
            <SmallValueCard value="ON" unit='' name='Pressure Control'/>
          }
          </Grid>
          <Grid item>
          {this.props.allParameters.isPressureControlState
            &&
            <SmallValueCard value={this.props.allParameters.respiratoryRate} unit='bpm' name='Respiratory Rate'/>
          }
          </Grid>

          <Grid item>
          {this.props.allParameters.isPressureControlState
            &&
            <SmallValueCard value={this.props.allParameters.inspiratoryTime} unit='s' name='Inspiratory Time'/>
          }
          </Grid>

          <Grid item>
          {!this.props.allParameters.isPressureControlState
            &&
            <SmallValueCard value="ON" unit='' name='Pressure Support'/>
          }
          </Grid>

          <Grid item>
          {!this.props.allParameters.isPressureControlState
            &&
            <SmallValueCard value={this.props.allParameters.sensitivity} unit='' name='Sensitivity'/>
          }
          </Grid>

          <Grid item>
          {!this.props.allParameters.isPressureControlState
            &&
            <SmallValueCard value={this.props.allParameters.apneaTime} unit='s' name='Apnea Time'/>
          }
          </Grid>
          </Grid>

          <Grid item direction="column" spacing={1} justify="space" alignItems="center">
          
            <Grid item>
            <SmallValueCard value={this.props.allParameters.fiO2} unit='%' name='FiO2'/>
            </Grid>

            <Grid item>
            <SmallValueCard value={this.props.allParameters.peep} unit='cmH2O' name='PEEP'/> 
            </Grid>

            <Grid item>
            <SmallValueCard value={this.props.allParameters.peakPressure} unit='cmH2O' name='Peak Pressure'/> 
            </Grid>
          </Grid>
        </Grid>

        <Grid
          container
          direction="row"
          alignItems="center"
          justify="center"
        >
          <Button className="standByButton" variant="contained" align="center" style={{ backgroundColor: "#D9A3DE" }}>
            <strong>
            Turn on Standby
            </strong>
            
          </Button>
        </Grid>
      </div>
      // <LineChart timeSeriesData={this.props.timeSeriesData} />
    );
  }
}
*/
