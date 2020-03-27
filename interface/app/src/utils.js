import {
    axisLeft,
    axisBottom,
    format,
    timeFormat,
    scaleTime,
    scaleLinear,
  } from 'd3';
  
  /**
   * create x- and y-scales
   */
  const xScale =
    scaleTime()
      .domain([dateUtils.getStartOfMonth(new Date()), new Date()])
      .range([0, d3Config.maxChartWidth]);
  
  const yScale =
    scaleLinear()
      .domain([0, d3Config.defaultMaxYValue])
      .range([d3Config.maxChartHeight, 0]);
  
  /**
   * scale data points according to their respective domain/range configuration
   */
  const scaleXData = (point) => {
    return xScale(new Date(point.timestamp));
  }
  
  const scaleYData = (point) => {
    return yScale(point.value);
  }
  
  /**
   * create x- and y-axes
   */
  const yAxis =
    axisLeft(yScale)
      .ticks(5)
      .tickFormat(format(d3Config.numberFormat));
  
  const xAxis =
    axisBottom(xScale)
      .ticks(5)
      .tickFormat(timeFormat(d3Config.dateFormat));