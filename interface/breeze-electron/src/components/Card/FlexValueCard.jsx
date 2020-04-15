import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import Typography from '@material-ui/core/Typography';
import NumberToggle from './NumberToggle'

const useStyles = theme => ({
  root: {
    width: "100%",
    height: "100%",
    borderRadius: 0,
    textAlign: "center",
    margin: "dense",
    boxShadow: "0px 0px 0px 0px rgba(0,0,0,0.2), 0px 0px 0px 0px rgba(0,0,0,0.14), 0px 0px 2px 0px rgba(0,0,0,0.12)",
  },
  good: {
    background: "#a5d6a7"
  },
  warn: {
    background: "#ffd54f"
  },
  alarm: {
    background: "#e57373"
  }
});

export const FlexValueCard = ({isEditing, classes, value, unit, min, max, readableName, increment, decrement}) => {
  
  // let classNames;
  // if (this.props.good) {
  //   classNames = `${classes.root} ${classes.good}`
  // } else if (this.props.warn) {
  //   classNames = `${classes.root} ${classes.warn}`
  // } else if (this.props.alarm) {
  //   classNames = `${classes.root} ${classes.alarm}`
  // } else {
  //   classNames = `${classes.root}`
  // }

  return(
      <Card className = {classes.root} style={{opacity: isEditing ? 1 : 0.6}}>
          <CardActionArea style={{padding: isEditing ? "10px 0" : "10px 0"}}>            
              <Typography variant="subtitle1" style={{fontFamily: "Barlow"}}>
                  {readableName}
              </Typography>
              <Typography variant="subtitle2" align="left" style={{position: "relative", top: 61, left: 112, fontFamily: "Barlow"}}>
                  {unit}
              </Typography>
              {isEditing 
                ? <NumberToggle min={min} max={max} value={value} increment={increment} decrement={decrement}/>
                : <Typography variant="h2" style={{opacity: 0.8}}>
                  {value} 
                  </Typography>}
          </CardActionArea>
      </Card>
  );
}

export default withStyles(useStyles)(FlexValueCard)
