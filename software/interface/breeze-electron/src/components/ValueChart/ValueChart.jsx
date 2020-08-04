import React, { Component } from 'react';
import PropTypes from 'prop-types';
import classNames from 'classnames';
import './css/ValueChart.css';

const DEFAULT_COLOR = '#040404';
class ValueChart extends Component {
  state = {}
  componentDidMount() {
    // For initial animation
    setTimeout(() => {
      this.setState({ setStrokeLength: true });
    });
  }
  render() {
    const { setStrokeLength } = this.state;
    const {
      className,
			radius,
      strokeWidth,
      dimension,
			color,
      goodFraction,
			goodColor,
			badColor,
			colorOpacity,
			currentValue,
			lowerBound,
			upperBound,
		} = this.props;

		// 
		
    
    const circleRadius = Math.min(radius, 85);
    const circumference = 2 * 3.14 * circleRadius;
    const strokeLength = setStrokeLength ? circumference / 100 * goodFraction : 0;
		return (
			<div
				className={classNames('value-chart', className, {
					'no-progress': strokeLength === 0
				})}
			>
				<svg viewBox="0 0 180 180" width={dimension} height={dimension} className="circSVG">
					<circle
						className="value-chart-total"
						stroke={color}
						strokeWidth={strokeWidth}
						fill="none"
						cx="90"
						cy="90"
						r={circleRadius}
					/>
					<circle
						className="value-chart-progress"
						stroke={color}
						strokeWidth={strokeWidth}
						strokeDasharray={`${strokeLength},${circumference}`}
						strokeLinecap="butt"
						fill="none"
						cx="90"
						cy="90"
						r={circleRadius}
					/>
					{/* <circle
						className="value-chart-progress"
						stroke={color}
						strokeWidth={strokeWidth}
						strokeDasharray={`${strokeLength},${circumference}`}
						strokeLinecap="butt"
						fill="none"
						cx="90"
						cy="90"
						r={circleRadius}
					/> */}
					<text x="90" y="90" text-anchor="middle" dominant-baseline="central" fill={color} font-size="60" font-weight="bold">{currentValue}</text>
				</svg>
			</div>
		);
  }
}
ValueChart.defaultProps = {
  radius: 80,
  progress: 100,
  strokeWidth: 30,
  dimension: 180,
  color: DEFAULT_COLOR,
};
ValueChart.propTypes = {
  className: PropTypes.string,
  radius: PropTypes.number,
  strokeWidth: PropTypes.number,
  color: PropTypes.string,
  progress: PropTypes.number,
  dimension: PropTypes.number
};
export default ValueChart;