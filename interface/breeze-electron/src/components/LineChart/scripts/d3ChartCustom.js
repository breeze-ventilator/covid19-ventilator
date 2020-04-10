import '../css/d3Chart.css'
import d3Config from './d3Config'

import {
  axisLeft,
  axisBottom,
	scaleLinear,
	// format,
} from 'd3';

import {
  // curveMonotoneX,
  line as d3Line,
  select,
} from 'd3';


export default class d3Chart {
    constructor(containerId, lineChartId, numDataPoints, yMin, yMax){
        this.containerId = containerId;
        this.lineChartId = lineChartId;

        this.yMin = yMin;
        this.numDataPoints = numDataPoints;

        this.xScale = 
            scaleLinear() // scales data to its position based on its input
                .domain([0, this.numDataPoints-1])
        
        this.yScale =
            scaleLinear()
                .domain([yMin,yMax])

        this.scaleXData = (d, i) => {
            return this.xScale(i);
        }

        this.scaleYData = (d, i) => {
            return this.yScale(d);
        }

        this.yAxis =
            axisLeft(this.yScale)
                .ticks(5)

        this.xAxis =
            axisBottom(this.xScale)
                .ticks(10)

    }

    getSvgDims() {
        let svgWidth = document.getElementById(this.containerId).offsetWidth;
        let svgHeight = document.getElementById(this.containerId).offsetHeight;
        
        const width = svgWidth - d3Config.margin.left -d3Config.margin.right;
        const height = svgHeight -d3Config.margin.top -d3Config.margin.bottom;
        
        return {width, height}
    }

    updateScales() {
        let svgDims = this.getSvgDims();
        let width = svgDims.width;
        let height = svgDims.height;
        
        this.yScale.range([height, 0]);
        this.xScale.range([0, width]);
    }

    buildAxes() {
        let svg = select('#' + this.lineChartId);
        let g = svg.append('g')
            .attr("transform", "translate(" +d3Config.margin.left + "," +d3Config.margin.top + ")");
        
        g.append('g')
            .attr('id', 'line-chart-yaxis' + this.lineChartId)
            .attr('class', 'line-chart-yaxis');
        
        g.append('g')
            .attr('id', 'line-chart-xaxis' + this.lineChartId)
            .attr('class', 'line-chart-xaxis');

    }

    buildLine() {
        select('#' + this.lineChartId)
          .append('path')
          .attr('id', 'line-chart-line' + this.lineChartId)
          .attr("transform", "translate(" +d3Config.margin.left + "," +d3Config.margin.top + ")");
    }

    drawAxes() {
        select('#line-chart-xaxis' + this.lineChartId)
          .call(this.xAxis);
      
        select('#line-chart-yaxis' + this.lineChartId)
          .call(this.yAxis);
    }

    drawLine(data) {
        const line = d3Line()
          .x(this.scaleXData)
          .y(this.scaleYData)
      
        select('#line-chart-line' + this.lineChartId)
          .attr('d', line(data));
    }

    renderChanges(data) {
        this.drawAxes();
        this.drawLine(data);
    }

    updateXAxisHeight() {
        select('#line-chart-xaxis' + this.lineChartId)
            .attr("transform", "translate(0," + this.yScale(this.yMin) + ")");
    }

        
    // Call all functions necessary to set up the chart
    initializeChart(data) {
        this.updateScales();
        this.buildAxes();
        this.buildLine();
        this.updateXAxisHeight();
        this.renderChanges(data);
    }
        
    handleNewData(data) {
        // adjustYScale(data);
        // adjustXScale(data, option);
        this.renderChanges(data);
    }


    setWidth(data) {
        this.updateScales();
        this.updateXAxisHeight();
        this.renderChanges(data);
    }

}
