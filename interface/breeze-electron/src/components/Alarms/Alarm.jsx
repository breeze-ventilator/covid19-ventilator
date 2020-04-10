import React from 'react';

export default class Alarm extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      min: this.props.min,
      max: this.props.max
  }
}
