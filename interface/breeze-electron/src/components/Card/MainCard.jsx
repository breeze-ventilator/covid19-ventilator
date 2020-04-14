import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import Typography from '@material-ui/core/Typography';
import ConcentricCircles from './ConcentricCircles';
import styled from "@emotion/styled";
import { keyframes } from '@emotion/core'


const sizes = {large: 500, medium: 380, small: 280};
const cardWidth = 440;
export const MainCard = ({ tidalVolume, respiratoryRate, low, high, minimized}) => {
    const size = tidalVolume < low
        ? "small"
        : tidalVolume < high
            ? "medium"
            : "large";
    const diameter = sizes[size]
    const radius = parseInt(diameter/2)
    const height = minimized ? 200 : 400;
    const verticalCenter = parseInt(height/2)
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
        <div style={{position: 'relative'}}>
        <Container height={height} minimized={minimized}>          
            <CircleContainer style={{
                left: (cardWidth/2 - radius),
                top: (verticalCenter - radius)
                }}>
                <ConcentricCircles 
                    // fill={size !== "medium" && "red"}
                    diameter={diameter}/>
            </CircleContainer>
            <Data>
                <VolumeDisp>
                <div>
                    <ValueText>
                        {tidalVolume}
                    </ValueText>
                    L
                </div>
                Tidal Volume
                </VolumeDisp>
            </Data>
        </Container>
        <TopCard>
            <VolumeDisp style={{position: "static"}}>
                <div>
                    <ValueText style={{fontSize: "50px"}}>
                        {respiratoryRate}
                    </ValueText>
                    bpm
                </div>
                Respiratory rate
            </VolumeDisp>
        </TopCard>
        </div>
    );
}

export default MainCard;

const Container = styled.div`
    margin: 20px;
    max-width: ${cardWidth}px;
    height: ${props => props.height}px;
    // ${({ height }) => height ? `${height}px` : `${cardWidth}px`};
    overflow: hidden;
    position: relative;
    ${props => !props.minimized && `box-shadow: 0px 15px 40px rgba(58, 140, 171, 0.19);`}
    border-radius: 15px;
    // margin-bottom: 40px;
`
const TopCard = styled.div`
    box-shadow: 0px 15px 40px rgba(58,140,171,0.19);
    border-radius: 15px;
    position: absolute;
    right: 0;
    background-color: white;
    top: -10px;
    text-align: center;
`
const fadeIn = keyframes`
    from { opacity: 0.5; } 
`
const CircleContainer = styled.div`
    position: absolute;
    animation: ${fadeIn} 1s infinite alternate;
`
const Data = styled.div`
    position: absolute;
    background-color: white;
    border-radius: 50%;
    min-height: 180px;
    min-width: 180px;
    text-align: center;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
`
const VolumeDisp = styled.div`
    padding: 20px;
    margin: auto;
    position: absolute;
    top: 0; left: 0; bottom: 0; right: 0;
`

const ValueText = styled.span`
    font-size: 90px;
`