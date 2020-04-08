import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Moment from 'react-moment';


const useStyles = theme => ({
  root: {

  },
  statusBar: {
    position: 'inline',
    top: 0,
    left: 0,
    background: 'rgba( 255, 255, 255, 0.8 )',
    height: '2em',
    width: '100%',
    lineHeight: '1.8',
    textAlign: 'center',
    display: 'flex'
  },
  battery: {
    position: "relative",
    marginTop: '5px',
    marginLeft: '15px',
    width: "40px",
    height: "15px",
    background: "black",
    clipPath: "polygon(95% 0, 0% 0%, 0% 100%, 95% 100%, 95% 75%, 100% 75%, 100% 25%, 95% 25)",
  },
  
  level: {
    position: "absolute",
    top: "0",
    bottom: "0",
    background: "limegreen",
    minWidth: "20px",
    boxShadow: "inset 0 0 0 2px black",
    width: "50%",
    maxWidth: "95%",
    transition: "width 1s .5s",
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
    backgroundColor: 'rgba( 0, 255, 0, 0.3 )',
    width: '70%',
  },
  right: {
      display: 'inline-block',
      width:'15%',
      float: 'right',
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
        }
        this.interval = null
    }

    componentDidUpdate(prevProps) {
    }

    componentDidMount() {
        const self = this;

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
        const level = <div class="level"></div>;

        
        return(
            
            <div className = {classes.statusBar}>
                <div className = {classes.left}>
                    <strong>
                        <Moment format="HH:MM a">{this.state.time}
                        </Moment>
                    </strong>
                </div>
                <div className = {classes.center}>
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
