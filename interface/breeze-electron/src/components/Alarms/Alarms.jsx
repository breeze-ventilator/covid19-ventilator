import React from 'react';

import ParameterInput from '../Alarms/AlarmsInput.jsx'
import Box from '@material-ui/core/Box';
import Container from '@material-ui/core/Container';
import Grid from '@material-ui/core/Grid';
import Button from '@material-ui/core/Button';
import {NotificationContainer, NotificationManager} from 'react-notifications';
import 'react-notifications/lib/notifications.css';

export default class Alarms extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      alarms: this.props.alarms
    }
    this.setParameterStateValue = this.setParameterStateValue.bind(this);
    this.saveAlarms = this.saveAlarms.bind(this);
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
          NotificationManager.error('Error message', 'Close after 3000ms', 3000);
          break;
        default:
          break;
      }
    };
  };

  saveAlarms() {
    this.props.setAlarms(this.state.alarms)
  }

  setParameterStateValue(parameterName, value) {
    let alarms = this.state.alarms;
    if (parameterName == "Low Minute Ventilation Alarm") {
      alarms["minuteVentilation"].min = value
    }
    else if (parameterName == "High Minute Ventilation Alarm") {
      alarms["minuteVentilation"].max = value
    }
    else if (parameterName == "Low Pressure Alarm") {
      alarms["pressure"].min = value
    }
    else if (parameterName == "High Pressure Alarm") {
      alarms["pressure"].max = value
    }
    this.setState({alarms: alarms})
  }

  render() {
    return (
      <div>
        <Box component="span" m={1}>
          <Container>
            <Grid 
              container
              alignItems="stretch"
              justify="space-between"
              spacing={3}
              direction="column"
            >
              <h2 style={{textAlign: "center", color: "#fff"}}>Alarm Settings</h2>

              <ParameterInput
                parameterName="Low Minute Ventilation Alarm"
                startingValue={this.props.alarms.minuteVentilation.min}
                setParameter={this.setParameterStateValue}
                step={2}
                min={0}
                max={100}
                unit={"%"}
              /> <br></br>
              <ParameterInput
                parameterName="High Minute Ventilation Alarm"
                startingValue={this.props.alarms.minuteVentilation.max}
                setParameter={this.setParameterStateValue}
                step={2}
                min={0}
                max={100}
                unit={"%"}
              /> <br></br>
              <ParameterInput
                parameterName="Low Pressure Alarm"
                startingValue={this.props.alarms.pressure.min}
                setParameter={this.setParameterStateValue}
                step={2}
                min={0}
                max={100}
                unit={"%"}
              /> <br></br>
              <ParameterInput
                parameterName="High Pressure Alarm"
                startingValue={this.props.alarms.pressure.max}
                setParameter={this.setParameterStateValue}
                step={2} 
                min={0} 
                max={100} 
                unit={"%"} 
              /> 

                <Grid item text-align="center" xl={6} md={6} sm={12} xs={12}>
                  <Button 
                    onClick={this.saveAlarms}
                    className="setParametersButton"
                    variant="contained"
                    align="center"
                    color="primary">
                      Save Changes
                  </Button>
                </Grid>
              </Grid>
            <NotificationContainer />
          </Container>
        </Box>
      </div>
    );
  }
}
