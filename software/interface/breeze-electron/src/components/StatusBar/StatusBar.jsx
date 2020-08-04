import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Moment from 'react-moment';
import Button from '@material-ui/core/Button';
import { Link } from 'react-router-dom';

const useStyles = theme => ({
  root: {

  },
  statusBar: {
    top: 0,
    left: 0,
    background: '#0E4362',
    color: 'white',
    height: '2em',
    width: '100%',
    display: 'flex',
  },
  battery: {
    position: 'relative',
    marginTop: '5px',
    marginLeft: '15px',
    width: '40px',
    height: '15px',
    background: 'black',
    clipPath: 'polygon(95% 0, 0% 0%, 0% 100%, 95% 100%, 95% 75%, 100% 75%, 100% 25%, 95% 25)',
  },
  level: {
    position: 'absolute',
    top: 0,
    bottom: 0,
    background: 'limegreen',
    minWidth: '20px',
    boxShadow: 'inset 0 0 0 2px black',
    width: '50%',
    maxWidth: '95%',
    transition: 'width 1s .5s',
  },
  left: {
    float: 'left',
    width:'15%',
    paddingLeft: '15px',
    paddingTop: 5
  },
  center: {
    display: 'inline-block',
    textAlign: 'center',
    background: '#072536',
    radius: '2px',
    color: 'white',
    width: '60%',
  },
  right: {
    float: 'right',
    width:'15%',
    paddingRight: '15px',
  },
});

const buttonStyle = {
  backgroundColor: "#072536", 
  color: "white", 
  fontFamily: "Barlow",
  fontSize: 16, 
  width:"100%", 
  height: "120%", 
  boxShadow: "0 48x 2px -2px rgba(58,140,171,0.24);"
}




class StatusBar extends React.Component {
    constructor(props) {
        super(props);

        this.state = {
            time: new Date(),
            batteryLevel: 0,
            isAlarm: true
        }

        this.interval = null
    }

    componentDidUpdate(prevProps) {
    }

    componentDidMount() {
        const self = this;

        // Updates time every 1 second.
        this.interval = setInterval(function() {
            self.setState({
                time: new Date(),
                batteryLevel: self.props.batteryLevel
            });
        }, 1000);
    }

    componentWillUnmount() {
        clearInterval(this.interval);
    }

    render() {
        const { classes } = this.props;

        return(

            <div className = {classes.statusBar}>
                <div className = {classes.left}>
                    <strong>
                        <Moment format="HH:MM a">{this.state.time}
                        </Moment>
                    </strong>
                </div>
                <div className = {classes.center} >
                   {this.state.isAlarm ?
                      <Button onClick={() => this.setState({ isAlarm: !this.state.isAlarm })} variant="contained" style={buttonStyle}
                          component = { Link } to="/alarms">
                          {/* // href="/diagnostics"> */}
                        <span>Diagnostics &nbsp; &nbsp; &nbsp; &nbsp;<p style={{display: "inline", fontFamily: "Barlow", backgroundColor: "9BD8D3", fontSize: 10, opacity: 0.8}}> Set Alarms ⥂</p></span>
                      </Button>
                      :
                      <Button onClick={() => this.setState({ isAlarm: !this.state.isAlarm })} variant="contained" style={buttonStyle}
                          component = { Link } to="/diagnostics">
                          <span> <p style={{display: "inline", fontFamily: "Barlow", fontSize: 10, opacity: 0.8}}>⥄ Diagnostics</p> &nbsp; &nbsp; &nbsp; Set Alarms </span>
                      </Button>
                    }
                    {/* Monitoring */}
                </div>
                <div className = {classes.right}>
                    <div className = {classes.battery}>
                        <div className = {classes.level} style={{width: this.props.batteryLevel*100 + "%"}}></div>
                    </div>
                </div>

            </div>
        );
    }
}

export default withStyles(useStyles)(StatusBar)
