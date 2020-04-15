import React from 'react';
// import {NotificationContainer, NotificationManager} from 'react-notifications';
// import 'react-notifications/lib/notifications.css';
import { inRange } from './AlarmsHelper';
import { store} from 'react-notifications-component';
import 'react-notifications-component/dist/theme.css';
import ReactHowler from 'react-howler'
import highSound from './sounds/highSound.mp3';

const acceptableRanges = {
  fiO2: {
    min: 21,
    max: 99
  },
  tidalVolume: {
    min: 1,
    max: 30
  },
  pressure: {
    min: 0,
    max: 35
  },
  riseTime: {
    min: 0,
    max: 1
  },
  inspiratoryTime: {
    min: 0,
    max: 100
  }
}

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
      store.addNotification({
        title: "WARNING!",
        message: newAlarms[data],
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
  }


  checkData() {
    let alarmRanges = Object.assign(acceptableRanges, this.props.alarms);
    let dataPieces = Object.assign(this.props.allData, this.props.allParameters);
    let dataAlarm = [];

    for (var data in dataPieces) {
      let val = dataPieces[data];
      let range = alarmRanges[data]; 

      if (range === undefined) continue;

      if(val == null) continue;

      if (!inRange(val, range)) {
        dataAlarm.push(data)
      } else if (this.state.currentlyAlarming.includes(data)) {
        let alarms = this.state.currentlyAlarming.filter(x => x != data)
        this.setState({currentlyAlarming: alarms});
        this.props.setCurrentlyAlarming(alarms);
      }
    } 

    let newAlarms = dataAlarm.filter(alarm => !this.state.currentlyAlarming.includes(alarm))
    let allAlarms = this.state.currentlyAlarming.concat(newAlarms)
    
    if(allAlarms.length == 0){
      this.state.playingSound = false;
    }
    this.alarm(newAlarms,allAlarms);
  }

  componentDidUpdate(prevProps) {
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
