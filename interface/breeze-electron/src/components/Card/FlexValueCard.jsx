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
        const { classes, isEditing } = this.props;

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
                    <Typography variant="subtitle1">
                        {this.props.readableName}
                    </Typography>
                    {isEditing ? <NumberToggle value={this.state.value}/>
                    : <Typography variant={this.props.prominence}>
                        {this.state.value} 
                    </Typography>}
                    <Typography variant="subtitle2">
                        {this.props.unit}
                    </Typography>
                </CardActionArea>
            </Card>
        );
    }
}

export default withStyles(useStyles)(FlexValueCard)
