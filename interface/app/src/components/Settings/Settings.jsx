import React from 'react';
import ParameterInput from '../ParameterInput/ParameterInput'
import Box from '@material-ui/core/Box';
import Container from '@material-ui/core/Container';
import Grid from '@material-ui/core/Grid';
import ToggleButton from '@material-ui/lab/ToggleButton';
import ToggleButtonGroup from '@material-ui/lab/ToggleButtonGroup';
import Button from '@material-ui/core/Button';

export default class Settings extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      type: "patientSupport",
      isPatientControlState: true
    }
  }

  togglePatientControlState = () => {
      this.setState({
        isPatientControlState: !this.state.isPatientControlState
      });
      console.log(this.state.isPatientControlState)
    }


  render() {
    return (
      <Box component="span" m={1}>
        <Container>
            <Grid container alignItems="stretch"justify="space-between" spacing={3} direction="column">
                <Grid item xl={6} md={6} sm={12} xs={12}>
                  <Grid container justify="space-evenly" spacing={3} direction="row">
                  {/* TODO: MAKE TOGGLE BUTTON WORK AND CHANGE PARAMETERS SHOWN */}
                  <ToggleButtonGroup
                      value={this.state.type}
                      exclusive
                      aria-label="text alignment"
                      onChange={this.togglePatientControlState}
                    >
                    <ToggleButton value="patientSupport" variant="contained" color="primary">Patient Support</ToggleButton>
                    <ToggleButton value="patientControl" variant="contained" color="secondary">Patient Control</ToggleButton>
                  </ToggleButtonGroup>
                  </Grid>
                </Grid>
                <ParameterInput parameterName="FiO2" parameterHelpText="ⓘ Ventilator initiates breathing." startingValue={80} step={2} min={21} max={100} unit={"%"}/>
                <ParameterInput parameterName="PEEP" parameterHelpText="ⓘ Ventilator initiates breathing." startingValue={20} step={2} unit={" cmH2O"}/>
                <ParameterInput parameterName="Sensitivity" parameterHelpText="ⓘ Ventilator initiates breathing." startingValue={80} step={2} />
                <ParameterInput parameterName="Pressure support point" parameterHelpText="ⓘ Ventilator initiates breathing."  startingValue={20} step={2} unit={" cmH2O"} />
                <ParameterInput parameterName="Inspiratory Time" parameterHelpText="ⓘ Ventilator initiates breathing." startingValue={0.3} step={2} unit={" L"} />
                {!this.state.isPatientControlState && <ParameterInput parameterName="Respiratory Time" parameterHelpText="ⓘ Ventilator initiates breathing." startingValue={0.3} step={2} unit={" L"} />}
                <Grid item text-align="center" xl={6} md={6} sm={12} xs={12}>
                  {/* TODO: ON BUTTON CLICK, need to get all of the above object's state values and call function in messager */}
                  <Button className="setParametersButton" variant="contained" align="center" color="primary">
                    Set Parameters
                  </Button>
                </Grid>
          </Grid>
        </Container>
      </Box>

    );
  }
}
