import React from 'react';
import ParameterInput from '../ParameterInput/ParameterInput'
import Box from '@material-ui/core/Box';
import Container from '@material-ui/core/Container';
import Grid from '@material-ui/core/Grid';
import Button from '@material-ui/core/Button';
import {NotificationContainer, NotificationManager} from 'react-notifications';
import 'react-notifications/lib/notifications.css';

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

  createNotification = (type) => {
    return () => {
      switch (type) {
        case 'info':
          NotificationManager.info('Info message');
          break;
        case 'success':
          NotificationManager.success('Success message', 'Title here');
          break;
        case 'warning':
          NotificationManager.warning('Warning message', 'Close after 3000ms', 3000);
          break;
        case 'error':
          // NotificationManager.error(`Tidal volume is ${this.state.data.tidalVolume}`, 'Error!', 5000, () => {
          //   alert('callback');
          // });
          NotificationManager.error('Currently 9L/min', 'Minute ventilation too high', 5000, () => {
            // alert('MINUTE VENTIALTION IS TOO HIGH!');
          });
          break;
        default:
          break;
      }
    };
  };
  /*TODO: Add an alarm history! */

  render() {
    return (
      <div>
<Box component="span" m={1}>
      <Container>
          <Grid container alignItems="stretch"justify="space-between" spacing={3} direction="column">
              <Grid item xl={6} md={6} sm={12} xs={12}>
                <Grid container justify="space-evenly" spacing={3} direction="row">
                </Grid>
              </Grid>
              <ParameterInput parameterName="Patient Body Weight" startingValue={80} step={2} min={0} max={100} unit={"pounds"}/>
              {/*TODO: Make the lower parameters appear only once the weight has been entered, and change startingValue accordingly. */}
              <br></br><br></br>
              <ParameterInput parameterName="Low Minute Ventilation Alarm" startingValue={5} step={2} min={0} max={100} unit={"%"}/>
              <ParameterInput parameterName="High Minute Ventilation Alarm" startingValue={10} step={2} min={0} max={100} unit={"%"}/>
              <br></br><br></br>
              <ParameterInput parameterName="Low Pressure Alarm" startingValue={4} step={2} min={0} max={100} unit={"%"}/>
              <ParameterInput parameterName="High Pressure Alarm" startingValue={40} step={2} min={0} max={100} unit={"%"}/>

              <Grid item text-align="center" xl={6} md={6} sm={12} xs={12}>
                <Button className="setParametersButton" onClick={this.createNotification('error')} variant="contained" align="center" color="primary">
                  Save Changes
                </Button>
                {/* // <Button className="btn btn-info" onClick={this.createNotification('error')}>
                //   Warning
                // </Button> */}
              </Grid>
        </Grid>
        <NotificationContainer />
      </Container>
    </Box>
      </div>


    );
  }
}
