import React from 'react';
import d3Utils from './utils';
// import d3Config from './config';
const d3Config = {
  svgHeight: 100,
}

export default class Graph extends React.Component {
  constructor(props) {
    // We'll fill this out soon
  }

  componentDidMount() {
    const { timeSeriesData } = this.props;
    d3Utils.initializeChart(timeSeriesData, 'monthToDate');
  }

  componentDidUpdate(prevProps) {
    // This too
  }

  componentWillUnmount() {
    // And finally this
  }

  render() {
    return (
      <svg className="line-chart" width="100%" height={d3Config.svgHeight} />
    );
  }
}