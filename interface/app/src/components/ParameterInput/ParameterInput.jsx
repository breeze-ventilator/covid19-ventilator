import React from 'react';
import mobiscroll from '@mobiscroll/react';
import '@mobiscroll/react/dist/css/mobiscroll.min.css';
import PropTypes from 'prop-types';
import Grid from '@material-ui/core/Grid';
import Card from '@material-ui/core/Card';

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
            value: inst.getVal() + this.props.unit
        });
    }

    onValueChange = (event) => {
        this.setState({
            value: +event.target.value + this.props.unit
        });
        event.target.value = event.target.value + this.props.unit;
    }

    render() {
      return (
            <Grid item xl={6} md={6} sm={12} xs={12}>
                <Card align>
                    <div align="center" className="parameterName">
                        <strong>
                        {this.props.parameterName}
                        </strong>
                    
                    </div>

                    <div class="inputField">
                        <mobiscroll.FormGroup inset>
                            <mobiscroll.Stepper
                                onClick={this.tap}
                                onChange={this.onValueChange}
                                ref="stepper"
                                className={this.props.className}
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
                            suffix={this.props.unit}
                        />
                    </div>

      <div align="center" className="parameterHelpText">{this.props.parameterHelpText}</div>
                    </Card>
                </Grid>
      );
    }
}


ParameterInput.defaultProps = {
    startingValue: 0,
    min: 0,
    max: 100,
    step: 10,
    className: 'default-input',
    parameterName: 'default-param-name',
    unit: ''
};
ParameterInput.propTypes = {
    startingValue: PropTypes.number,
    min: PropTypes.number,
    max: PropTypes.number,
    step: PropTypes.number,
    className: PropTypes.string,
    unit: PropTypes.string
};

export default ParameterInput;
