import React from 'react';
import d3Chart from './scripts/d3ChartCustom';
import d3Config from './scripts/d3Config'
import Typography from '@material-ui/core/Typography';


export default class LineChart extends React.Component {
    constructor(props) {
      super(props);

      this.callSetWidth = this.callSetWidth.bind(this);
      this.chart = new d3Chart(this.props.containerId, this.props.lineChartId, this.props.numDataPoints, this.props.yMin, this.props.yMax);
    }

    componentDidMount() {
      this.chart.initializeChart(this.props.timeSeriesData);
      window.addEventListener('resize', this.callSetWidth);
    }

    componentDidUpdate(prevProps) {
      this.chart.handleNewData(this.props.timeSeriesData);

    }

    componentWillUnmount() {
      window.removeEventListener('resize', this.callSetWidth);
    }

    callSetWidth() {
      this.chart.setWidth(this.props.timeSeriesData);
    }

    render() {
      return (
        <div className="chart">
          <Typography variant="h3" align="center" color="inherit" className={this.props.titleClass}>
              {this.props.chartTitle}
          </Typography>
          <div id={this.props.containerId}>
            <svg id={this.props.lineChartId} className={this.props.lineClass} width="100%" height="250px" />
          </div>
        </div>
      );
    }
  }
