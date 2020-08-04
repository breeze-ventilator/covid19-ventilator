import React from 'react';
// import {NotificationContainer, NotificationManager} from 'react-notifications';
// import 'react-notifications/lib/notifications.css';
import { shouldAlarm } from './AlarmsHelper';
import { store} from 'react-notifications-component';
import 'react-notifications-component/dist/theme.css';
import ReactHowler from 'react-howler'
import highSound from './sound/highSound.mp3'

export default class AlarmsHandler extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      currentlyAlarming: [],
      ringingIds: [],
      playingSound: false
    }

    this.checkData = this.checkData.bind(this)
    this.alarm = this.alarm.bind(this)
  }
  
  alarm(newAlarms,allAlarms) {
    if (newAlarms.length > 0) {
      this.setState({ currentlyAlarming: allAlarms});
      this.props.setCurrentlyAlarming(allAlarms);
    }
 
    for (var data in newAlarms) {
      this.createAlarm(newAlarms[data])
    }
  }

  createAlarm(data) {
    store.addNotification({
      title: data,
      message: " ",
      type: "danger",
      insert: "top",
      container: "top-right",
      animationIn: ["animated", "fadeIn"],
      animationOut: ["animated", "fadeOut"],
      width: 250
    })
    if(!this.state.playingSound){
      this.state.playingSound = true;
    }
  }

  // alarmFromArduino(alarmType){
  //   // FiO2 low, FiO2 high
  //   if(!this.state.currentlyAlarming.includes(alarmType)){
  //     this.state.currentlyAlarming.push(alarmType)
  //     this.createAlarm(alarmType)
  //   }
  // }

  checkData() {
    let alarmRanges = this.props.alarms;
    let dataPieces = Object.assign(this.props.allData);
    let dataAlarm = [];
    for (var data in dataPieces) {
      let val = dataPieces[data];
      if(val == null) continue;
      const alarmMessage = shouldAlarm(data, val, alarmRanges);
      if (alarmMessage) {
        dataAlarm.push(alarmMessage)
      } else if (this.state.currentlyAlarming.includes(data)) {
        let alarms = this.state.currentlyAlarming.filter(x => x != data)
        this.setState({currentlyAlarming: alarms});
        this.props.setCurrentlyAlarming(alarms);
      }
    } 
    let newAlarms = dataAlarm.filter(alarm => !this.state.currentlyAlarming.includes(alarm))
    let allAlarms = [...this.state.currentlyAlarming, ...newAlarms]
    
    if(allAlarms.length == 0){
      this.state.playingSound = false;
    }
    this.alarm(newAlarms,allAlarms);
  }

  componentDidUpdate(prevProps) {
    // if(this.props.receivedAlarmFromArduino){
    //   this.alarmFromArduino(this.props.arduinoAlarmType)
    // }
    this.checkData();
  }

  render() {
    return (
      <ReactHowler
        src={highSound}
        playing={this.state.playingSound}
        volume={1.0}
      />
    )
  }
}
