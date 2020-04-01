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
                            <Message.Header>Was this what you wanted?</Message.Header>
                            <p>Did you know it's been a while? Did you know it's been a while? Did you know it's been a while?</p>
                            </Message>
                        </div>
                        <div style={divStyle}>
                            <Message info>
                            <Message.Header>Was this what you wanted?</Message.Header>
                            <p>Did you know it's been a while? Did you know it's been a while? Did you know it's been a while?</p>
                            </Message>
                        </div>
                        <div style={divStyle}>
                            <Message info>
                            <Message.Header>Was this what you wanted?</Message.Header>
                            <p>Did you know it's been a while? Did you know it's been a while? Did you know it's been a while?</p>
                            </Message>
                        </div>
                        <div style={divStyle}>
                            <Message info>
                            <Message.Header>Was this what you wanted?</Message.Header>
                            <p>Did you know it's been a while? Did you know it's been a while? Did you know it's been a while?</p>
                            </Message>
                        </div>
                    </div>
                    <Button className="continueButton" onClick={() => {this.props.doneSetup(); this.state.text = "Done Setup!"; this.state.done = true}} variant="contained" align="center" color="primary">
                              Continue
                    </Button>
                    </div>
          }

      </div>


    );
  }
}
