import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Modal from '@material-ui/core/Modal';


const useStyles = theme => ({
    root: {
        position: 'absolute',
        top: '250px !important',
      }
});
  

class SimpleModal extends React.Component {
    constructor(props) {
        super(props);

        this.state = {
            open: this.props.open
        }

        this.handleOpen = this.handleOpen.bind(this);
        this.handleClose = this.handleClose.bind(this);
    }

    handleOpen() {
        this.setState({open: true});
    }

    handleClose() {
        this.props.modalClose();
    }

    componentDidUpdate(prevProps, prevState){
        if (prevProps != this.props) {
            this.setState({open: this.props.open});
        }
    }


    render() {
        const { classes } = this.props;
        return(
            <Modal
                open={this.state.open}
                onClose={this.handleClose}
                className={classes.root}
            >
            {this.props.children}
            </Modal>
        );
    }
}

export default withStyles(useStyles)(SimpleModal)
