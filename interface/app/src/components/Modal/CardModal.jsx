import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Modal from '@material-ui/core/Modal';

const useStyles = theme => ({
    root: {
      width: "100%",
      height: "100%",
      borderRadius: 0,
      textAlign: "center",
      margin: "dense",
    }
  });
  

class CardModal extends React.Component {
    constructor(props) {
        super(props);

        this.state = {
            open: false
        }

        this.handleOpen = this.handleOpen.bind(this);
        this.handleClose = this.handleClose.bind(this);
    }

    handleOpen() {
        this.setState({open: true});
    }

    handleClose() {
        this.setState({open: false});
    }

    componentDidUpdate(prevProps) {
        const { value } = this.props;
        this.state.value = value;
    }


    render() {
        const { classes } = this.props;
        return(
            <Card className = {classes.root}>
                <CardActionArea>            
                    <Typography variant="subtitle1">
                        {this.props.name}
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

export default withStyles(useStyles)(CardModal)
