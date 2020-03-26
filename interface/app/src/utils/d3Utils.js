import {
	axisLeft,
	axisBottom,
	format,
	timeFormat,
	scaleTime,
	scaleLinear,
} from 'd3';
import { select } from 'd3';
import {
  curveMonotoneX,
  line as d3Line,
} from 'd3';


// create x- and y-scales
const xScale =
	scaleTime()
		.domain([dateUtils.getStartOfMonth(new Date()), new Date()])
		.range([0, d3Config.maxChartWidth]);

const yScale =
	scaleLinear()
		.domain([0, d3Config.defaultMaxYValue])
		.range([d3Config.maxChartHeight, 0]);

// scale data points according to their respective domain/range configuration
const scaleXData = (point) => {
	return xScale(new Date(point.timestamp));
}

const scaleYData = (point) => {
	return yScale(point.value);
}

// create x- and y-axes
const yAxis =
	axisLeft(yScale)
		.ticks(5)
		.tickFormat(format(d3Config.numberFormat));

const xAxis =
	axisBottom(xScale)
		.ticks(5)
				.tickFormat(timeFormat(d3Config.dateFormat));


// build the elements that will be contained within our main SVG
const buildAxes = () => {
  select('.line-chart')
    .append('g')
    .attr('class', 'line-chart-yaxis');

  select('.line-chart')
    .append('g')
    .attr('class', 'line-chart-xaxis')
};

const buildLine = () => {
  select('.line-chart')
    .append('path')
    .attr('class', 'line-chart-line')
};

/**
 * draw elements of the chart based on current settings
 */
const drawAxes = () => {
  select('.line-chart-xaxis')
    .call(xAxis);

  select('.line-chart-yaxis')
    .call(yAxis);
}

const drawLine(data) {
  const line = d3Line()
    .x(scaleXData)
    .y(scaleYData)
    .curve(curveMonotoneX);

  select('.line-chart-line')
    .attr('d', line(data));
}

/**
 * invoke functions to draw appropriate changes
 */
const renderChanges = (data) => {
  drawAxes();
  drawLine(data);
}

/**
 * Call all functions necessary to set up the chart
 */
const initializeChart = (data) => {
  buildAxes();
  buildLine();
  renderChanges(data);
}