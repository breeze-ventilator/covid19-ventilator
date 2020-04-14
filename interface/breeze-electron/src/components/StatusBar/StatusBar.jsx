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
    background: '#0B3045',
    color: 'white',
    height: '2em',
    width: '100%',
    lineHeight: 1.8,
    textAlign: 'center',
    display: 'flex'
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
    textAlign: 'left',
    paddingLeft: '15px',
  },
  center: {
    display: 'inline-block',
    textAlign: 'center',
    background: '#072536',
    radius: '2px',
    color: 'white',
    width: '70%',
  },
  right: {
    float: 'right',
    width:'15%',
    textAlign: 'right',
    paddingRight: '15px',
  },
});




class StatusBar extends React.Component {
    constructor(props) {
        super(props);

        this.state = {
            time: new Date(),
            batteryLevel: 0
        /*
            classes: makeStyles({
                root: {
                  width: 500,
                },
              }),
              value: 0,
            viewForm: false*/
        }
        /*this.page = null;*/

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
                <div className = {classes.center}>
                   {/* <Button onClick={increment} variant="contained" style={{backgroundColor: "rgba(0,0,0,255)", padding:0, boxShadow: "none", width:"100%"}}
                        component = { Link  }
                        to="/diagnostics">
                      Monitoring
                    </Button>*/}
                    Monitoring
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