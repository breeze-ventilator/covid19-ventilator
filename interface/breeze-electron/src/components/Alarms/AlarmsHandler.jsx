import React from 'react';
import {NotificationContainer, NotificationManager} from 'react-notifications';
import 'react-notifications/lib/notifications.css';
import { inRange } from './AlarmsHelper';

const acceptableRanges = {
  peep: {
    min: 5,
    max: 30
  },
  fiO2: {
    min: 21,
    max: 99 
  },
  tidalVolume: {
    min: 4,
    max: 9
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
    max: 5
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
  
  alarm(data, severity) {
    if (this.state.currentlyAlarming.includes(data)) return

    if (severity === "high") {
      NotificationManager.error("Warning!", data)
    } else {
      NotificationManager.warning("Warning!", data)
    }

    let newAlarms = this.state.currentlyAlarming.concat([data])
    this.setState({ currentlyAlarming: newAlarms });
  }


  checkData() {
    for (var data in this.props.allData) {
      let val = this.props.allData[data];
      let range = acceptableRanges[data]; 
      if (!inRange(val, range)) {
        console.log(`Alert - ${data}`);
        this.alarm(data, "high");
      }
    }
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
