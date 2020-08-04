import React from 'react';
import "regenerator-runtime";
import NumPad from 'react-numpad';
import PropTypes from 'prop-types';
import Button from '@material-ui/core/Button';
import ButtonGroup from '@material-ui/core/ButtonGroup';
import Card from '@material-ui/core/Card';
import Typography from '@material-ui/core/Typography';
import Grid from '@material-ui/core/Grid';
import '../Vitals/css/vitals.css';

class ParameterInputCustom extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            value: this.props.startingValue,
        };

        this.handleIncrement = this.handleIncrement.bind(this)
        this.handleDecrement = this.handleDecrement.bind(this)
        this.setParameter = this.setParameter.bind(this);
        this.handleChange = this.handleChange.bind(this);
    }

    componentDidUpdate(prevProps, prevState){

    }

    handleChange(value){
        // handle min
        if(value <= this.props.min) {
            value = this.props.min;
        }

        // handle max
        else if(value >= this.props.max) {
            value = this.props.max;
        }

        this.setState({value});
        this.props.setParameter(this.props.parameterName, this.state.value);

    }

    handleIncrement(){
        const newValue = this.state.value - this.props.step
        this.setState({value: this.state.value + this.props.step});
        this.props.setParameter(this.props.parameterName, newValue);
    }

    handleDecrement(){
        const newValue = this.state.value - this.props.step
        if((this.state.value - this.props.step) >= 0){
            this.setState({value: newValue});
        }
        this.props.setParameter(this.props.parameterName, newValue);
    }

    setParameter(){
        this.props.setParameter(this.props.parameterName, this.state.value);
        this.props.modalClose();
    }

    render() {
      return (
        <Grid container justify="center">
            <Card align="center" style={{maxWidth: "65%"}}>
                    <Typography style={{marginTop: "10px", fontFamily: "Barlow"}}variant="subtitle1">
                        {this.props.parameterName}
                    </Typography>
                <ButtonGroup size="medium"align="center" variant="contained" color="default">
                    <Button style={{width: '60px', height:'40px', fontSize:"14px", backgroundColor: "#9BD8D3", color: "white"}} onClick={this.handleDecrement}>-</Button>
                    <NumPad.Number
                        className="md-numpad"
                        decimal={true}
                        negative={false}
                        onChange={this.handleChange}
                    >
                    <Button style={{width: '120px', height:'40px', fontSize:"14px", color: "black", fontFamily: "Barlow"}} disabled>{this.state.value + " " + this.props.unit}</Button>
                    </NumPad.Number>
                    <Button style={{width: '60px', height:'40px', fontSize:"14px", backgroundColor: "#9BD8D3", color: "white"}} onClick={this.handleIncrement}>+</Button>
                </ButtonGroup>
                <Typography style={{marginTop:"10px", marginBottom:"10px", marginLeft: "20px", marginRight: "20px", fontFamily: "Barlow"}} variant="subtitle1">
                </Typography>

            </Card>
        </Grid>
      );
    }
}


ParameterInputCustom.defaultProps = {
    startingValue: 0,
    min: 0,
    max: 100,
    step: 10,
    className: 'default-input',
    parameterName: 'default-param-name',
    unit: ''
};
ParameterInputCustom.propTypes = {
    startingValue: PropTypes.number,
    min: PropTypes.number,
    max: PropTypes.number,
    step: PropTypes.number,
    className: PropTypes.string,
    unit: PropTypes.string,
    modalClose: PropTypes.func
};

export default ParameterInputCustom;
