import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import BottomNavigation from '@material-ui/core/BottomNavigation';
import BottomNavigationAction from '@material-ui/core/BottomNavigationAction';
import RestoreIcon from '@material-ui/icons/Restore';
import FavoriteIcon from '@material-ui/icons/Favorite';
import LocationOnIcon from '@material-ui/icons/LocationOn';
import Vitals from '../Vitals/Vitals';
import { Link } from 'react-router-dom';


export default class SimpleBottomNavigation extends React.Component{
  constructor(props) {
    super(props);

    this.state = {
      classes: makeStyles({
        root: {
          width: 500,
        },
      }),
      value: 0,
      viewForm: false
    }

    this.page = null;
  }

  render() {
    return(
  <BottomNavigation
        value={this.state.value}
        onChange={(event, newValue) => {
          this.state.value = newValue;
        }}
        showLabels
        className={this.state.classes.root}
      >
        <BottomNavigationAction
          label="Parameters"
          icon={<RestoreIcon />}
          onPress={() => this.setState(
            { page: <Vitals timeSeriesData={this.state.data.tidalVolume} />,
             viewForm: true
           }
            )}
          />

        <BottomNavigationAction
          label="Diagnostics"
          icon={<FavoriteIcon />}
          onPress={() => this.setState(
            { page: <Vitals timeSeriesData={this.state.data.tidalVolume} />,
            viewForm: true }
            )}
        />

        <BottomNavigationAction
          label="Alarms"
          icon={<LocationOnIcon />}
          onPress={() => this.setState(
            { page: <Vitals timeSeriesData={this.state.data.tidalVolume} />,
            viewForm: true }
            )}
          />

        <div>
          {(this.state.viewForm) ?
          this.page : this.page}
        </div>
      </BottomNavigation>
    );
  }
}


