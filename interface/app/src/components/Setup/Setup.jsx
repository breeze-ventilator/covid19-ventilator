import React from 'react';

import ParameterInput from '../ParameterInput/ParameterInput'
import Box from '@material-ui/core/Box';
import Container from '@material-ui/core/Container';
import Grid from '@material-ui/core/Grid';
import Button from '@material-ui/core/Button';
import {NotificationContainer, NotificationManager} from 'react-notifications';
import 'react-notifications/lib/notifications.css';
import Settings from '../Settings/Settings';
import { Message } from 'semantic-ui-react';
const headerStyle = {
    color: 'black',
    textAlign: 'center',
    marginTop: '50px'
};

const divStyle = {
    width: '300px',
    padding: '10px',
    textAlign:'left',
    display: 'inline-block'
};
const mainDivStyle = {
    width: '100%',
    padding: '25px',
    textAlign:'center'
};



export default class Setup extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
        text: "Before you Breeze",
        done: false
    }
  }

  componentDidUpdate(prevProps){
  }


  render() {
    return (
      <div>
          {/* hacky fix if done then show settings  */}
          {this.state.done &&
            <Settings allParameters={this.props.allParameters} setParameters={this.props.setParameters}/>
          }
          {!this.state.done &&
                    <div>

          
                    <h1 style={headerStyle}>{this.state.text}</h1>
                    <div style={mainDivStyle}>
                        <div style={divStyle}>
                            <Message info>
                            <Message.Header>Did you assemble the ventilator circuit?</Message.Header>
                            <p>You need to put together the circuit, HME filter, and Tracheal suction.</p>
                            </Message>
                        </div>
                        <div style={divStyle}>
                            <Message info>
                            <Message.Header>Did you perform the initial validation tests?</Message.Header>
                            <p className="runValTestsButton" align="center">
                              <Button variant="contained" align="center" color="default">
                              Run Validation Tests
                              </Button>
                            </p>
                            </Message>
                        </div>
                        <div style={divStyle}>
                            <Message info>
                            <Message.Header>Did you hear the backup alarm when starting up the machine?</Message.Header>
                            <p>If not, the backup alarm may not be functioning.</p>
                            </Message>
                        </div>
                    </div>
                    <div align="right">
                    <Button className="continueButton" onClick={() => {this.props.doneSetup(); this.state.text = "Done Setup!"; this.state.done = true}} variant="contained" align="center" color="primary">
                              Continue
                    </Button>
                    </div>
                    </div>
          }

      </div>


    );
  }
}
