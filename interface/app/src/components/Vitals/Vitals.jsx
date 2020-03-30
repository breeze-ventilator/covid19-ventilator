import React from 'react';
import LineChart from '../LineChart/LineChart';

export default class Vitals extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <LineChart timeSeriesData={this.props.timeSeriesData} />
    );
  }
}
