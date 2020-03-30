import React from 'react';
import mobiscroll from '@mobiscroll/react';
import '@mobiscroll/react/dist/css/mobiscroll.min.css';
import PropTypes from 'prop-types';
mobiscroll.settings = {
    theme: 'ios',
    themeVariant: 'light'
};


class ParameterInput extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            value: this.props.startingValue,
        };
    }

    tap = () => {
        this.refs.numpad.instance.show();
    }

    onSet = (event, inst) => {
        this.setState({
            value: inst.getVal()
        });
    }

    onValueChange = (event) => {
        this.setState({
            value: +event.target.value
        });
    }

    render() {
      return (
        <div>
            <mobiscroll.FormGroup inset>
                <mobiscroll.Stepper 
                    onClick={this.tap} 
                    onChange={this.onValueChange} 
                    ref="stepper" 
                    className="md-price" 
                    data-role="stepper" 
                    min={this.props.min} 
                    max={this.props.max} 
                    step={this.props.step} 
                    value={this.state.value} 
                    readOnly />
            </mobiscroll.FormGroup>
           
            <mobiscroll.Numpad
                className="md-numpad"
                ref="numpad"
                preset="decimal"
                min={this.props.min}
                max={this.props.max}
                scale={0}
                type="hidden"
                value={this.state.value}
                onSet={this.onSet}
            />
        </div>
      );
    }
}


ParameterInput.defaultProps = {
    startingValue: 0,
    min: 0,
    max: 100,
    step: 10,
};
ParameterInput.propTypes = {
    startingValue: PropTypes.number,
    min: PropTypes.number,
    max: PropTypes.number,
    step: PropTypes.number,
};

export default ParameterInput;