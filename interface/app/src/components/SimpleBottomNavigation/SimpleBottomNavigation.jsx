import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import BottomNavigation from '@material-ui/core/BottomNavigation';
import BottomNavigationAction from '@material-ui/core/BottomNavigationAction';
import RestoreIcon from '@material-ui/icons/Restore';
import FavoriteIcon from '@material-ui/icons/Favorite';
import LocationOnIcon from '@material-ui/icons/LocationOn';
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
      <div>
<BottomNavigation
        value={this.state.value}
        onChange={(event, newValue) => {
          this.state.value = newValue;
        }}
        showLabels
        className={this.state.classes.root}
      >
        <BottomNavigationAction
          label="Settings"
          icon={<RestoreIcon />}
          component = { Link }
          to="/settings"
          />

        <BottomNavigationAction
          label="Diagnostics"
          icon={<FavoriteIcon />}
          component = { Link  }
          to="/diagnostics"
        />

        <BottomNavigationAction
          label="Alarms"
          icon={<LocationOnIcon />}
          component = { Link }
          to="/alarms"
          />
      </BottomNavigation>
      </div>
    );
  }
}


