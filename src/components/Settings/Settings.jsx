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
      isPressureControlState: this.props.allParameters.isPressureControlState,
      fiO2: this.props.allParameters.fiO2, // Control + Support
      peep: this.props.allParameters.peep, // Control + Support
      peakPressure: this.props.allParameters.peakPressure, // Control + Support
      sensitivity: this.props.allParameters.sensitivity, // Support
      apneaTime: this.props.allParameters.apneaTime, // Support
      inspiratoryTime: this.props.allParameters.inspiratoryTime, // Control
      respiratoryRate: this.props.allParameters.respiratoryRate // Control
    }
    this.setStateValue = this.setStateValue.bind(this);
  }

  togglePatientControlState = () => {
      this.setState({
        isPressureControlState: !this.state.isPressureControlState
      });

      console.log(this.state.isPressureControlState)
    }

  setStateValue(parameterName,value){
    if(parameterName == "FiO2"){
      this.state.fiO2 = value;
    }
    else if(parameterName == "PEEP"){
      this.state.peep = value;
    }
    else if(parameterName == "Peak Pressure"){
      this.state.peakPressure = value;
    }
    else if(parameterName == "Sensitivity"){
      this.state.sensitivity = value;
    }
    else if(parameterName == "Apnea Time"){
      this.state.apneaTime = value;
    }
    else if(parameterName == "Inspiratory Time"){
      this.state.inspiratoryTime = value;
    }
    else if(parameterName =="Respiratory Rate"){
      this.state.respiratoryRate = value;
    }
    this.setState(this.state)
  }

  render() {
    return (
      <Box component="span" m={1}>
        <Container>
        <br></br>
            <Grid container alignItems="stretch"justify="space-between" spacing={2} direction="column">
                <Grid item xl={6} md={6} sm={12} xs={12}>
                  <Grid container justify="space-evenly" spacing={5} direction="row">
                  
                  <ToggleButtonGroup
                      value={this.state.isPressureControlState ? "patientControl" : "patientSupport" }
                      exclusive
                      aria-label="text alignment"
                      onChange={this.togglePatientControlState}
                    >
                    <ToggleButton value="patientSupport" variant="contained" color="primary">Pressure Support</ToggleButton>
                    <ToggleButton value="patientControl" variant="contained" color="secondary">Pressure Control</ToggleButton>
                  </ToggleButtonGroup>
                  </Grid>
                </Grid>
                <br></br><br></br>

                {/* CONTROL ONLY PARAMETERS */}
                {this.state.isPressureControlState 
                  &&
                  <ParameterInput setParameter={this.setStateValue} parameterName="Respiratory Rate" parameterHelpText="" startingValue={this.props.allParameters.respiratoryRate} step={2} unit={" bpm"} />
                }
                {this.state.isPressureControlState 
                  &&  
                  <ParameterInput parameterName="Inspiratory Time" setParameter={this.setStateValue} parameterHelpText="" startingValue={this.props.allParameters.inspiratoryTime} step={2} unit={" s"} />
                }

                {/* SUPPORT ONLY PARAMETERS */}
                {!this.state.isPressureControlState &&
                  <ParameterInput parameterName="Sensitivity" setParameter={this.setStateValue} parameterHelpText="" startingValue={this.props.allParameters.sensitivity} step={2} />
                }
                {!this.state.isPressureControlState &&
                  <ParameterInput parameterName="Apnea Time" setParameter={this.setStateValue} parameterHelpText="" startingValue={this.props.allParameters.apneaTime} step={2} unit={" s"} />
                }

                {/* SHARED PARAMETERS */}
                <ParameterInput parameterName="FiO2" setParameter={this.setStateValue} parameterHelpText="" startingValue={this.props.allParameters.fiO2} step={2} min={21} max={100} unit={"%"}/>
                <ParameterInput parameterName="PEEP" setParameter={this.setStateValue} parameterHelpText="" startingValue={this.props.allParameters.peep} step={2} unit={" cmH2O"}/>
                <ParameterInput parameterName="Peak Pressure" setParameter={this.setStateValue} parameterHelpText=""  startingValue={this.props.allParameters.peakPressure} step={2} unit={" cmH2O"} />
                <Grid item text-align="center" xl={6} md={6} sm={12} xs={12}>
                  <Button className="setParametersButton" onClick={() => {this.props.setParameters(this.state)}} variant="contained" align="center" color="primary">
                    Set Parameters
                  </Button>
                </Grid>
          </Grid>
        </Container>
      </Box>

    );
  }
}
