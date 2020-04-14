import React from 'react';
import FlexValueCard from '../Card/FlexValueCard';
import Grid from "@material-ui/core/Grid";
import './css/vitals.css'
import Card from '@material-ui/core/Card';
import MainCard from '../Card/MainCard';
import Typography from '@material-ui/core/Typography';
import Button from '@material-ui/core/Button';
import ButtonGroup from '@material-ui/core/ButtonGroup';
import SimpleModal from '../Modal/SimpleModal';
import ParameterInputCustom from '../ParameterInput/ParameterInputCustom';
import PatientProfile from '../PatientProfile/PatientProfile';


const parameterInfo = {
  fiO2: {readableName: "FiO2", unit: "%"},
  peep: {readableName: "PEEP", unit: "cm H2O"},
  // peakPressure: {readableName: "Peak pressure", unit: "L"},
  inspiratoryPressure: {readableName: "Inspiratory pressure", unit: "cm H2O"},
  inspiratoryTime: {readableName: "Inspiratory time", unit: "%"},
  respiratoryRate: {readableName: "Respiratory rate", unit: "bpm"},
  sensitivity: {readableName: "Sensitivity", unit: "L/min"},
  apneaTime: {readableName: "Apnea time", unit: "s"},
  flowCyclingOff: {readableName: "Flow cycling off", unit: ""}
};
const controlParams = ["fiO2", "peep", "inspiratoryPressure", "inspiratoryTime", "respiratoryRate"];
const supportParams = ["fiO2", "peep", "inspiratoryPressure", "sensitivity", "apneaTime", "flowCyclingOff"];

export default class Vitals extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      data: {
        tidalVolume: 5,
        pressure: 5,
      },
      parameters: {...this.props.allParameters},
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
    //TODO: call this somewhere
    this.setState({parameters: {...this.state.parameters, [parameterName]: value}});
    // TODO: Actually update parameters as well for arduino.
  }

  setModalStateValues(parameterName, value, unit){
    // TODO: this is bad, never mutate state
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
    const parameterNames = this.state.parameters.mode == "Pressure Control"
      ? controlParams
      : supportParams;
    let footer = (
        <Grid container className="bottom">
            {parameterNames.map((name) => 
            <Grid item xs={4}>
              <FlexValueCard 
                alarm={this.isAlarming(name)}
                value={this.state.parameters[name]}
                prominence="h2"
                readableName={parameterInfo[name].readableName} 
                unit={parameterInfo[name].unit}
                isEditing={true} // DEBUG: use this to toggle mode @Anna
              />
            </Grid>)}
        </Grid>);
    return (
      <div className="mainContainer" style={{fontFamily: "Barlow"}}>
        {/* Header Observables */}
        <MainCard
          alarm={this.isAlarming("tidalVolume")} 
          tidalVolume={this.state.data.tidalVolume}
          respiratoryRate={this.state.data.respiratoryRate}
          prominence="h1"
          high={14}
          low={13}
        />

        {/*Parient Profile*/}
        {/* <PatientProfile /> */}

        {/* TODO: Graphs go here */} 
        {/* <LineChart timeSeriesData={this.props.timeSeriesData} /> */}

        {/* Footer modifiables */}
        { footer }
        {/* {this.state.modal.startingValue != 'Pressure Control' && this.state.modal.startingValue != "Pressure Support" &&
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
        } */}
     </div>
    )};
}
