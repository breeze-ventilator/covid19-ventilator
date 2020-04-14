import React from 'react';
import { withStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActionArea from '@material-ui/core/CardActionArea';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import Typography from '@material-ui/core/Typography';
import ConcentricCircles from './ConcentricCircles';
import styled from "@emotion/styled";
import { keyframes } from '@emotion/core';
import Button from '@material-ui/core/Button';
import ExpandLessIcon from '@material-ui/icons/ExpandLess';
import ExpandMoreIcon from '@material-ui/icons/ExpandMore';

const sizes = {large: 500, medium: 380, small: 280};
const cardWidth = 440;
const verticalCenter = 220;
export const NumberToggle = ({ value, increment, decrement }) => {

    return(
        <div style={{textAlign: 'center', padding: "10 0"}}>
            <div style={{}}>
            <Button 
                onClick={increment}
                variant="contained" 
                style={{position: "absolute", backgroundColor: "rgba(0,0,0,0)", padding:0, boxShadow: "none", width:"100%", height: "50%", top: 0, left: 0}}>
                <ExpandLessIcon style={{position: "absolute", top: 50}}/></Button>

                <Value variant="h2">
                    {value} 
                </Value>
            <Button 
                onClick={decrement}
                variant="contained" 
                style={{position: "absolute", backgroundColor: "rgba(0,0,0,0)", padding:0, boxShadow: "none", width:"100%", height: "50%", bottom: 0, left: 0}}>
                    <ExpandMoreIcon style={{position: "absolute", top: 38}}/></Button> 
            <br></br>
            </div>
            <div style={{padding: "10px"}}>
            <Typography align="center" style={{fontFamily: "Barlow", fontStyle: "Bold", padding: "10px"}} variant="subtitle3">
                Recommended: <p style={{display: "inline", color: "#4abe48"}}><b>50-60</b></p>
            </Typography> 
            </div>
        </div>

    );
}

export default NumberToggle;
const Value = styled(Typography)`
    padding: 20px;
`
const Container = styled.div`
    margin: 20px;
    max-width: ${cardWidth}px;
    height: ${cardWidth}px;
    overflow: hidden;
    position: relative;
    box-shadow: 0px 15px 40px rgba(58, 140, 171, 0.19);
    border-radius: 15px;
    margin-bottom: 40px;
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