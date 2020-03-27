import './d3Chart.css'
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

const margin = {top: 20, right: 20, bottom: 20, left: 40};

function getSvgDims() {
  let svgWidth = document.getElementById('line-chart-container').offsetWidth;
  let svgHeight = document.getElementById('line-chart-container').offsetHeight;
  
  const width = svgWidth - margin.left - margin.right;
  const height = svgHeight - margin.top - margin.bottom;

  return {width, height}
}

// create x- and y-scales
const numDataPoints = 10
const xScale =
  scaleLinear() // scales data to its position based on its input
    .domain([0, numDataPoints-1])
    //.range([0, defaultSvgDims.width]);

const yScale =
  scaleLinear()
    .domain([-10, 10])
    //.range([defaultSvgDims.height, 0]);

// scale data points according to their respective domain/range configuration
const scaleXData = (d, i) => {
  return xScale(i); //.value
}

const scaleYData = (d, i) => {
  return yScale(d);
}

// create x- and y-axes
const yAxis =
  axisLeft(yScale)
    .ticks(5)
    //  .tickFormat(format(d3Config.numberFormat));

const xAxis =
  axisBottom(xScale)
    .ticks(10)
		// .tickFormat(format(d3Config.numberFormat));


function updateScales() {
  let svgDims = getSvgDims();
  let width = svgDims.width;
  let height = svgDims.height;
  
  yScale.range([height, 0]);
  xScale.range([0, width]);
}

// build the elements that will be contained within our main SVG
const buildAxes = () => {
  let svg = select('.line-chart');
  console.log(svg.attr("width"))
  let g = svg.append('g')
    .attr("transform", "translate(" + margin.left + "," + margin.top + ")");;
  
  g.append('g')
    .attr('class', 'line-chart-yaxis');

  g.append('g')
    .attr('class', 'line-chart-xaxis')
    //.attr("transform", "translate(0," + yScale(0) + ")");
};

const buildLine = () => {
  select('.line-chart')
    .append('path')
    .attr('class', 'line-chart-line')
    .attr("transform", "translate(" + margin.left + "," + margin.top + ")");
};


// draw elements of the chart based on current settings
const drawAxes = () => {
  select('.line-chart-xaxis')
    .call(xAxis);

  select('.line-chart-yaxis')
    .call(yAxis);
}

const drawLine = (data) => {
  const line = d3Line()
    .x(scaleXData)
    .y(scaleYData)
    // .curve(curveMonotoneX);

  select('.line-chart-line')
    .attr('d', line(data));
}

// invoke functions to draw appropriate changes
const renderChanges = (data) => {
  drawAxes();
  drawLine(data);
}

// Call all functions necessary to set up the chart
function initializeChart(data) {
  updateScales();
  buildAxes();
  buildLine();
  updateXAxisHeight();
  renderChanges(data);
}
    
function handleNewData(data) {
	// adjustYScale(data);
	// adjustXScale(data, option);
	renderChanges(data);
}

const updateXAxisHeight = () => {
  select('.line-chart-xaxis')
    .attr("transform", "translate(0," + yScale(0) + ")");
}

function setWidth(data) {
  updateScales();
  updateXAxisHeight();
  renderChanges(data);
}

export {initializeChart, handleNewData, setWidth, d3Config}