import React from 'react';
import FlexValueCard from '../Card/FlexValueCard';
import Grid from "@material-ui/core/Grid";
import './css/vitals.css'
import Card from '@material-ui/core/Card';
import Typography from '@material-ui/core/Typography';
import Button from '@material-ui/core/Button';
import ButtonGroup from '@material-ui/core/ButtonGroup';
import SimpleModal from '../Modal/SimpleModal';
import ParameterInputCustom from '../ParameterInput/ParameterInputCustom';


export default class Vitals extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      data: {
        tidalVolume: 5,
        pressure: 5,
      },
      parameters: {
        mode: this.props.allParameters.mode, // one of Pressure Control, Pressure Support, Standby
        fiO2: this.props.allParameters.fiO2, // Control + Support
        peep: this.props.allParameters.peep, // Control + Support
        peakPressure: this.props.allParameters.peakPressure, // Control + Support
        sensitivity: this.props.allParameters.sensitivity, // Support
        apneaTime: this.props.allParameters.apneaTime, // Support
        inspiratoryTime: this.props.allParameters.inspiratoryTime, // Control
        respiratoryRate: this.props.allParameters.respiratoryRate // Control
      },
      modal: {
        open: false,
        parameterName: '',
        startingValue: 0,
        step: 1,
        min: 0,
        max: 100,
        unit: '%'
      }
    }
    this.setParameterStateValue = this.setParameterStateValue.bind(this);
    this.setModalStateValues = this.setModalStateValues.bind(this);
    this.modalClose = this.modalClose.bind(this);
    this.isAlarming = this.isAlarming.bind(this);
    this.changeMode = this.changeMode.bind(this);
  }

  componentDidUpdate(prevProps){
    this.state.data = this.props.allData;
    this.state.parameters = this.props.allParameters;
    if (this.isMount) {
      this.setState(this.state);
    }
  }

  isAlarming(value) {
    return this.props.currentlyAlarming.includes(value)
  }

  setParameterStateValue(parameterName,value){
    if(parameterName == 'FiO2'){
      this.state.parameters.fiO2 = value;
    }
    else if(parameterName == 'PEEP'){
      this.state.parameters.peep = value;
    }
    else if(parameterName == 'Peak Pressure'){
      this.state.parameters.peakPressure = value;
    }
    else if(parameterName == 'Sensitivity'){
      this.state.parameters.sensitivity = value;
    }
    else if(parameterName == 'Apnea Time'){
      this.state.parameters.apneaTime = value;
    }
    else if(parameterName == 'Inspiratory Time'){
      this.state.parameters.inspiratoryTime = value;
    }
    else if(parameterName =='Respiratory Rate'){
      this.state.parameters.respiratoryRate = value;
    }
    this.setState(this.state);

    // TODO: Actually update parameters as well for arduino.
  }

  setModalStateValues(parameterName, value, unit){
    if(parameterName == 'FiO2'){
      this.state.modal.step = 1;
      this.state.modal.min = 0;
      this.state.modal.max = 100;
    }
    else if(parameterName == 'PEEP'){
      this.state.modal.step = 1;
      this.state.modal.min = 0;
      this.state.modal.max = 100;
    }
    else if(parameterName == 'Peak Pressure'){
      this.state.modal.step = 1;
      this.state.modal.min = 0;
      this.state.modal.max = 100;
    }
    else if(parameterName == 'Sensitivity'){
      this.state.modal.step = 1;
      this.state.modal.min = 0;
      this.state.modal.max = 100;
    }
    else if(parameterName == 'Apnea Time'){
      this.state.modal.step = 1;
      this.state.modal.min = 0;
      this.state.modal.max = 100;
    }
    else if(parameterName == 'Inspiratory Time'){
      this.state.modal.step = 1;
      this.state.modal.min = 0;
      this.state.modal.max = 100;
    }
    else if(parameterName =='Respiratory Rate'){
      this.state.modal.step = 1;
      this.state.modal.min = 0;
      this.state.modal.max = 100;
    }

    this.state.modal.startingValue = value;
    this.state.modal.parameterName = parameterName;
    this.state.modal.unit = unit;
    this.state.modal.open = true;

    if(parameterName == "mode"){
      this.state.parameters.mode = value
    }

    this.setState(this.state);
  }

  modalClose(){
    this.state.modal.open = false;
    this.setState(this.state);
  }

  changeMode(value){
    this.state.parameters.mode = value;
    this.state.modal.open = false;
    this.setState(this.state)
  }

  render() {
    let footer;
    if (this.state.parameters.mode == "Pressure Control") {
      footer = (
        <Grid container className="bottom">
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard onClickHandler={this.setModalStateValues} value="Pressure Control" unit=" " prominence="h4" name="Mode"/>
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard alarm={this.isAlarming("fiO2")} onClickHandler={this.setModalStateValues} value={this.state.parameters.fiO2} unit="%" prominence="h2" name="FiO2" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard alarm={this.isAlarming("respiratoryRate")} onClickHandler={this.setModalStateValues} value={this.state.parameters.respiratoryRate} unit="" prominence="h2" name="Respiratory Rate" />
            </Grid>
          </Grid>
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard alarm={this.isAlarming("peep")} onClickHandler={this.setModalStateValues} value={this.state.parameters.peep} unit="cm H2O" prominence="h2" name="PEEP" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard alarm={this.isAlarming("inspiratoryTime")} onClickHandler={this.setModalStateValues} value={this.state.parameters.inspiratoryTime} unit="s" prominence="h2" name="Inspiratory Time" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard alarm={this.isAlarming("peakPressure")} onClickHandler={this.setModalStateValues} value={this.state.parameters.peakPressure} unit="cm H2O" prominence="h2" name="Peak Pressure" />
            </Grid>
          </Grid>
        </Grid>);
    } else if(this.state.parameters.mode == "Pressure Support") {
      footer = (
        <Grid container className="bottom">
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard onClickHandler={this.setModalStateValues} value="Pressure Support" unit=" " prominence="h4" name="Mode" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard onClickHandler={this.setModalStateValues} value={this.state.parameters.fiO2} unit="%" prominence="h2" name="FiO2" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard onClickHandler={this.setModalStateValues} value={this.props.allParameters.sensitivity} unit="" prominence="h2" name="Sensitivity" />
            </Grid>
          </Grid>
          <Grid container direction="row">
            <Grid item xs={4}>
              <FlexValueCard onClickHandler={this.setModalStateValues} value={this.state.parameters.peep} unit="cm H2O" prominence="h2" name="PEEP" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard onClickHandler={this.setModalStateValues} value={this.state.parameters.apneaTime} unit="s" prominence="h2" name="Apnea Time" />
            </Grid>
            <Grid item xs={4}>
              <FlexValueCard onClickHandler={this.setModalStateValues} value={this.state.parameters.peakPressure} unit="cm H2O" prominence="h2" name="Peak Pressure" />
            </Grid>
          </Grid>
        </Grid>
      )};
 
    return (
      <div className="mainContainer">
        {/* Header Observables */}
        <Grid container direction="row">
          <Grid item xs={6}>
              <FlexValueCard
                alarm={this.isAlarming("tidalVolume")} 
                value={this.state.data.tidalVolume}
                unit='mL'
                prominence="h1"
                name='Tidal Volume'
              />
          </Grid>
          <Grid item xs={6}>
              <FlexValueCard
                alarm={this.isAlarming("ie")}
                value={"1:3"}
                prominence="h1"
                unit='ratio'
                name='I:E Ratio'
              />
          </Grid>
        </Grid>

        {/* TODO: Graphs go here */} 
        {/* <LineChart timeSeriesData={this.props.timeSeriesData} /> */}
        <Button onClick={() => this.props.sendToArduino()} style = {{marginBottom:"50px", height:"80px",fontSize:"20px", marginTop:"10px",backgroundColor:"green",color:"white"}} variant="contained">SEND THE PARAMS!</Button>
        {/* Footer modifiables */}
        { footer }
        {this.state.modal.startingValue != 'Pressure Control' && this.state.modal.startingValue != "Pressure Support" &&
        <SimpleModal modalClose={this.modalClose} open={this.state.modal.open}>
          <div>
            <ParameterInputCustom parameterName={this.state.modal.parameterName} setParameter={this.setParameterStateValue} modalClose = {this.modalClose} startingValue={parseInt(this.state.modal.startingValue)} step={this.state.modal.step} min={this.state.modal.min} max={this.state.modal.max} unit={this.state.modal.unit}/>
          </div>
        </SimpleModal>
        }
        {(this.state.modal.startingValue == 'Pressure Control' || this.state.modal.startingValue == "Pressure Support") &&
        <SimpleModal modalClose={this.modalClose} open={this.state.modal.open}>
          <div align="center">
          <Card align="center" style={{maxWidth: "65%"}}>
                <Typography variant="h3" style={{paddingTop:"10px"}}>
                    Mode
                </Typography>
                <ButtonGroup
                  orientation="vertical"
                  align="center"
                  style={{width: '65%'}}
                >
                    <Button  onClick={() => this.changeMode("Pressure Control")} style = {{marginBottom:"50px", height:"80px",fontSize:"20px", marginTop:"10px",backgroundColor:"green",color:"white"}} variant="contained">Pressure Control</Button>
                    <Button  onClick={() => this.changeMode("Pressure Support")} style = {{marginBottom:"50px", height:"80px",fontSize:"20px",backgroundColor:"green",color:"white"}} variant="contained">Pressure Support</Button>
                    <Button onClick={() => this.changeMode("Standby")} style = {{marginBottom:"10px", height:"80px",fontSize:"20px",backgroundColor:"green",color:"white"}} variant="contained">Standby</Button>
                </ButtonGroup>
            </Card>
          </div>
          
        </SimpleModal>
        }
     </div>
    )};
}
