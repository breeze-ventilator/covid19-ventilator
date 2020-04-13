import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import Button from '@material-ui/core/Button';
import ExpandLessIcon from '@material-ui/icons/ExpandLess';
import Typography from '@material-ui/core/Typography';

const useStyles = theme => ({
  root: {
    width: "100%",
    height: "100%",
    borderRadius: 0,
    textAlign: "center",
    margin: "dense"
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

class FlexValueCard extends React.Component {
    constructor(props) {
        super(props);

        this.state = {
            value: 0,
            viewForm: false
        }

      this.openModal = this.openModal.bind(this);
    }

    openModal() {
        this.props.onClickHandler(this.props.name, this.props.value, this.props.unit)
    }

    componentDidUpdate(prevProps) {
        const { value } = this.props;
        this.state.value = value;
    }

    render() {
        const { classes } = this.props;

        let classNames;
        if (this.props.good) {
          classNames = `${classes.root} ${classes.good}`
        } else if (this.props.warn) {
          classNames = `${classes.root} ${classes.warn}`
        } else if (this.props.alarm) {
          classNames = `${classes.root} ${classes.alarm}`
        } else {
          classNames = `${classes.root}`
        }

        return(
            <Card className = {classNames}>
                <CardActionArea onClick={this.openModal}>     
                       
                    {this.props.name=="FiO2" && <Button variant="contained">small</Button>}
                    {this.props.name == "Respiratory Rate" && <Button variant="contained" style={{backgroundColor: "#eee", padding:0, minWidth:"30px"}}><ExpandLessIcon/></Button>}
                    {this.props.name == "Inspiratory Time" && <Button variant="contained" style={{backgroundColor: "#ddd", padding:0, minWidth:"30px"}}><ExpandLessIcon/></Button>}
                    {this.props.name == "PEEP" && <Button variant="contained" style={{backgroundColor: "#ddd", padding:0, boxShadow: "none", minWidth:"30px"}}><ExpandLessIcon/></Button>}
                    {this.props.name == "Peak Pressure" && <Button variant="contained" style={{backgroundColor: "#eee", padding:0, boxShadow: "none"}}><ExpandLessIcon/></Button>}
                    <Typography variant="subtitle1">
                        {this.props.readableName}
                    </Typography>
                    <Typography variant={this.props.prominence}>
                        {this.state.value} 
                    </Typography>
                    <Typography variant="subtitle2">
                        {this.props.unit}
                    </Typography>
                </CardActionArea>
            </Card>
        );
    }
}

export default withStyles(useStyles)(FlexValueCard)
