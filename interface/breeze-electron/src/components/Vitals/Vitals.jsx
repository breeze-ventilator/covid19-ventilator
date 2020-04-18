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
import styled from "@emotion/styled";
import { modes, parameterInfo, controlParams, supportParams } from '../../util/constants';

import Fab from '@material-ui/core/Fab';
import CreateIcon from '@material-ui/icons/Create';

function safeValue(fieldName, val){
  return Math.min(parameterInfo[fieldName].max, Math.max(parameterInfo[fieldName].min, val))
}

export default class Vitals extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      data: {
        tidalVolume: 5,
        pressure: 5,
      },
      isEditing: false,
      ...this.props.allParameters
    }
    this.setParameterStateValue = this.setParameterStateValue.bind(this);
    this.isAlarming = this.isAlarming.bind(this);
    // this.changeMode = this.changeMode.bind(this);
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

  toggleMode(value){
    this.state.mode = modes[(modes.indexOf(value) + 1) % 3];
    console.log(value);
    console.log(modes.indexOf(value) + 1)
    // this.state.modal.open = false;
    this.setState(this.state)
  }

  updateBMI = (BMI) => {
    this.setState({ userBMI : BMI})
  }

  updateIdealWeight = (idealWeight) => {
    this.setState({ userIdealWeight : idealWeight})
  }

  updateBreathingRate = (breathingRate) => {
    this.setState({ userBreathingRate : breathingRate})
  }

  updateParameterInfo(){
    const PEEP = userBMI <= 30 ? 5 : 8;
    const inspiratoryPressure = userIdealWeight * 7.5;
    const minRespiratoryRate = userBreathingRate <= 25 ? userBreathingRate + 2 : 24;

    //TODO: set these as parameterInfo
  }

  toggleEdit = () => {
    this.setState(prevState => ({isEditing: !prevState.isEditing}))
  }

  done = () => {
    this.toggleEdit();
    this.props.setParameters(this.state);
  }

  increment = (fieldName) => {
    let currentValue = this.state[fieldName];
    let defaultValue = parameterInfo[fieldName].default;

    // step size should be different at boundary conditions
    let step;
    let distanceToClosestValidPoint = (defaultValue - currentValue) % parameterInfo[fieldName].step;
    if (distanceToClosestValidPoint == 0) {
      step = parameterInfo[fieldName].step;
    } else if (currentValue == parameterInfo[fieldName].min) {
      step = distanceToClosestValidPoint;
    } else {
      step = 0;
    }
    let newValue = currentValue + step;
    this.setState(({[fieldName]: safeValue(fieldName, newValue)})) // we technically don't need safeValue anymore
  }

  decrement = (fieldName) => {
    let currentValue = this.state[fieldName];
    let defaultValue = parameterInfo[fieldName].default;

    // step size should be different at boundary conditions
    // (e.g. if we increment from the min of 21 and step is 10, we should go up to 30 not 31)
    let step;
    let distanceToClosestValidPoint = (currentValue - defaultValue) % parameterInfo[fieldName].step;
    if (distanceToClosestValidPoint == 0) {
      step = parameterInfo[fieldName].step;
    } else if (currentValue == parameterInfo[fieldName].max) {
      step = distanceToClosestValidPoint;
    } else {
      step = 0;
    }
    let newValue = currentValue - step
    this.setState(({[fieldName]: safeValue(fieldName, newValue)}))

    // this.setState(prevState => ({[fieldName]: safeValue(fieldName, prevState[fieldName] - parameterInfo[fieldName].step)}))
  }
  render() {
    const {isEditing, mode} = this.state
    const parameterNames = mode == "Pressure Control"
      ? controlParams
      : supportParams;
    let footer = (
        <div style={{position: 'relative' }}>
          <div style={{paddingLeft: "20px", fontFamily: "Barlow"}}>Mode:</div>
          <Header>
            <Button style = {{fontFamily: "Barlow", textAlign: "left"}} onClick={() => {this.toggleMode(mode)}} >
              {mode}
            </Button >
          </Header>
          {!isEditing
          ? <Fab size="small"
            style={{position:'absolute', right:'10px', top:'5px', boxShadow: "0px 3px 5px -1px rgba(0,0,0,0.1), 0px 6px 10px 0px rgba(0,0,0,0.04), 0px 1px 18px 0px rgba(0,0,0,0.12)",
            backgroundColor: '#33B0A6', color: "white"}}
            // backgroundColor: '#eee'}}
            onClick={this.toggleEdit}
            >
            <CreateIcon/>
          </Fab>
          : <Button variant="contained"
          style={{position:'absolute',
          right:'10px', top:'5px', color: "white",
          backgroundColor: "#33B0A6", padding:0, boxShadow: "none"}}
          onClick={this.done}
          > done </Button>
          }
        <Grid container>
            {parameterNames.map((name) =>
            <Grid item xs={4}>
              <FlexValueCard
                alarm={this.isAlarming(name)}
                value={this.state[name]}
                readableName={parameterInfo[name].readableName}
                unit={parameterInfo[name].unit}
                min={parameterInfo[name].recMin}
                max={parameterInfo[name].recMax}
                increment={() => this.increment(name)}
                decrement={() => this.decrement(name)}
                isEditing={isEditing} // DEBUG: use this to toggle mode @Anna
              />
            </Grid>)}
        </Grid>
        </div>);
    return (
      <div className="mainContainer" style={{fontFamily: "Barlow"}}>
        {/* Header Observables */}
        <MainCard
          alarm={this.isAlarming("tidalVolume")}
          minimized={isEditing}
          tidalVolume={this.state.data.tidalVolume}
          respiratoryRate={this.state.data.trueRespiratoryRate}
          prominence="h1"
          high={14}
          low={13}
        />
        <PatientProfile setup={this.props.setup} toggleSetupHandler={this.props.toggleSetupHandler}/>

        {/* TODO: Graphs go here */}
        {/* <LineChart timeSeriesData={this.props.timeSeriesData} /> */}
        {/* <Button onClick={() => this.props.sendToArduino()} style = {{marginBottom:"50px", height:"80px",fontSize:"20px", marginTop:"10px",backgroundColor:"green",color:"white"}} variant="contained">SEND THE PARAMS!</Button> */}
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
const Header = styled.span`
    font-size: 25px;
    color: #33B0A6;
    padding-left: 20px;
`
