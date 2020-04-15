import React from 'react';
import {NotificationContainer, NotificationManager} from 'react-notifications';
import 'react-notifications/lib/notifications.css';
import { inRange } from './AlarmsHelper';

const acceptableRanges = {
  peep: {
    min: 2,
    max: 30
  },
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
      currentlyAlarming: []
    }

    this.checkData = this.checkData.bind(this)
    this.alarm = this.alarm.bind(this)
  }
  
  alarm(dataAlarm) {
    let newAlarms = dataAlarm.filter(alarm => !this.state.currentlyAlarming.includes(alarm))
    let allAlarms = this.state.currentlyAlarming.concat(newAlarms)

    if (newAlarms.length > 0) {
      this.setState({ currentlyAlarming: allAlarms});
      this.props.setCurrentlyAlarming(allAlarms);
    }
 
    for (var data in newAlarms) {
      NotificationManager.error("Warning!", newAlarms[data])
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

    this.alarm(dataAlarm);
  }

  componentDidUpdate(prevProps) {
    this.checkData();
  }

  render() {
    return (
      <NotificationContainer />
    )
  }
}
