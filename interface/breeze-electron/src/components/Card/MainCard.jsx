import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import Typography from '@material-ui/core/Typography';
import ConcentricCircles from './ConcentricCircles';
import styled from "@emotion/styled";

const sizes = {large: 500, medium: 300};
const cardWidth = 440;
const verticalCenter = 220;
export const MainCard = ({ value, low, high}) => {
    const size = value < low
        ? "small"
        : value < high
            ? "medium"
            : "large";
    const diameter = sizes[size]
    const radius = parseInt(diameter/2)
    // const { classes } = this.props;

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
        <Container>          
            <div style={{position: "absolute", 
                left: (cardWidth/2 - radius),
                top: (verticalCenter - radius)
                }}>
                <ConcentricCircles 
                    fill={size !== "medium" && "red"}
                    diameter={diameter}/>
            </div>
            <div style={{textAlign: "center"}}>
                <div style={{backgroundColor: "white", borderRadius: 30}}>
                    hello
                </div>
            </div>
            {/* <Typography variant="subtitle1">
                {this.props.readableName}
            </Typography>
            <Typography variant={this.props.prominence}>
                {this.state.value} 
            </Typography>
            <Typography variant="subtitle2">
                {this.props.unit}
            </Typography> */}
        </Container>
    );
}

export default MainCard;

const Container = styled.div`
    margin: 20px;
    max-width: ${cardWidth}px;
    height: ${cardWidth}px;
    overflow: hidden;
    position: relative;
    box-shadow: 0px 15px 40px rgba(58, 140, 171, 0.19);
    border-radius: 15px;
`