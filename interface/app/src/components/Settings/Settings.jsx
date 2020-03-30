import React from 'react';
import ParameterInput from '../ParameterInput/ParameterInput'

export default class Settings extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <div>
        Settings
        <ParameterInput />
      </div>
    );
  }
}
