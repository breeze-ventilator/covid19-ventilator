import React from 'react';
import {initializeChart, handleNewData, setWidth} from './scripts/d3Chart';
import d3Config from './scripts/d3Config'

export default class LineChart extends React.Component {
    constructor(props) {
      super(props);

      this.callSetWidth = this.callSetWidth.bind(this);
    }

    componentDidMount() {
			const { timeSeriesData } = this.props;
      initializeChart(timeSeriesData);
      window.addEventListener('resize', this.callSetWidth);
    }

    componentDidUpdate(prevProps) {
      const { timeSeriesData } = this.props;
      // if (JSON.stringify(prevProps.timeSeriesData) != JSON.stringify(timeSeriesData))  {
        // console.log("HERE")
      handleNewData(timeSeriesData);
    }

    componentWillUnmount() {
      window.removeEventListener('resize', this.callSetWidth);
    }

    callSetWidth() {
      const { timeSeriesData } = this.props;
      setWidth(timeSeriesData);
    }

    render() {
      return (
        <div id='line-chart-container'>
          <svg className="line-chart" width="100%" height={d3Config.svgDefaultHeight} />
        </div>
      );
    }
  }
