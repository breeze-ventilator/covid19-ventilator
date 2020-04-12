import React from 'react';
import "regenerator-runtime";
import NumPad from 'react-numpad';
import Button from '@material-ui/core/Button';
import ButtonGroup from '@material-ui/core/ButtonGroup';
import PropTypes from 'prop-types';
import Grid from "@material-ui/core/Grid";
import Card from '@material-ui/core/Card';

class Numpad extends React.Component {

    constructor(props) {
        super(props);
        this.state = {
            value: this.props.startingValue,
        };

        this.handleIncrement = this.handleIncrement.bind(this)
        this.handleDecrement = this.handleDecrement.bind(this)
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

    render() {
        return (
            <Grid container justify="center">
                <Card align="center" style={{maxWidth: "65%"}}>
                    <p style={{marginBottom: 0}}>
                        {this.props.profileItemName}
                    </p>
                    <ButtonGroup style={{margin:"4px"}}size="medium"align="center" variant="contained" color="primary">
                        <Button style={{width: '60px', height:'40px', fontSize:"14px"}} onClick={this.handleDecrement}>-</Button>
                        <NumPad.Number
                            className="md-numpad"
                            decimal={true}
                            negative={false}
                            value={this.state.value}
                            onChange={this.handleChange}
                        >
                        <Button style={{width: '120px', height:'40px', fontSize:"14px", color: "black"}} disabled>{this.state.value + " " + this.props.unit}</Button>
                        </NumPad.Number>
                        <Button style={{width: '60px', height:'40px', fontSize:"14px"}} onClick={this.handleIncrement}>+</Button>
                    </ButtonGroup>
                    </Card>
            </Grid>
          );
      }
  }

  Numpad.defaultProps = {
    startingValue: 0,
    min: 0,
    max: 100,
    step: 10,
    className: 'default-input',
    profileItemName: 'default-param-name',
    unit: ''
};
Numpad.propTypes = {
    startingValue: PropTypes.number,
    min: PropTypes.number,
    max: PropTypes.number,
    step: PropTypes.number,
    className: PropTypes.string,
    unit: PropTypes.string
};

export default Numpad;