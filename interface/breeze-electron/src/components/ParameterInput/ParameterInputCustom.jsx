import React from 'react';
import PropTypes from 'prop-types';
import Button from '@material-ui/core/Button';
import ButtonGroup from '@material-ui/core/ButtonGroup';
import Card from '@material-ui/core/Card';
import Typography from '@material-ui/core/Typography';
import Grid from '@material-ui/core/Grid';
import mobiscroll from '@mobiscroll/react';
import '@mobiscroll/react/dist/css/mobiscroll.min.css';


mobiscroll.settings = {
    theme: 'ios',
    themeVariant: 'light'
};


class ParameterInputCustom extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            value: this.props.startingValue,
        };

        this.handleIncrement = this.handleIncrement.bind(this)
        this.handleDecrement = this.handleDecrement.bind(this)
        this.setParameter = this.setParameter.bind(this);
        this.handleKeypad = this.handleKeypad.bind(this);
    }

    componentDidUpdate(prevProps, prevState){

    }

    handleIncrement(){
        if((this.state.value + this.props.step) <= this.props.max){
            this.state.value += this.props.step;
            this.setState(this.state);
        }
    }

    handleDecrement(){
        if((this.state.value - this.props.step) >= this.props.min){
            this.state.value -= this.props.step;
            this.setState(this.state);
        }
    }

    handleKeypad(){
        this.refs.numpad.instance.show();
    }

    setParameter(){
        this.props.setParameter(this.props.parameterName, this.state.value);
    }



    render() {
      return (
        <Grid container justify="center">
            <Card align="center" style={{maxWidth: "65%"}}>
                <Typography variant="h2" style={{paddingTop:"10px"}}>
                    {this.props.parameterName}
                </Typography>
                <ButtonGroup style={{margin:"40px",marginBottom:"0px"}}size="large"align="center" variant="contained" color="primary">
                    <Button style={{width: '150px', height:'80px', fontSize:"36px"}} onClick={this.handleDecrement}>-</Button>
                    <Button style={{width: '180px', height:'80px', fontSize:"36px", color: "black"}} onClick={this.handleKeypad} disabled>{this.state.value + " " + this.props.unit}</Button>
                    <Button style={{width: '150px', height:'80px', fontSize:"36px"}} onClick={this.handleIncrement}>+</Button>
                </ButtonGroup>
                <Typography style={{marginTop:"5px", marginBottom:"40px"}} variant="subtitle1">
                    Usually this is from values of 80 to 30. :)
                </Typography>

                <mobiscroll.Numpad className="md-numpad" ref="numpad" preset="decimal" min={this.props.min} max={this.props.max} scale={0} type="hidden" value={this.state.value} onSet={this.onSet} suffix={this.props.unit} />

                <Button style={{width: '300px', height:'80px', margin:"40px", fontSize:"24px", backgroundColor:"green",color:"white"}}variant="contained">Set Parameter</Button>
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
    unit: PropTypes.string
};

export default ParameterInputCustom;
