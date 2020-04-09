import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardActions from '@material-ui/core/CardActions';
import CardContent from '@material-ui/core/CardContent';
import Button from '@material-ui/core/Button';
import Typography from '@material-ui/core/Typography';
import './css/Card.css'
import Grid from "@material-ui/core/Grid";

export default class ValueCard extends React.Component{
    constructor(props) {
        super(props);

        this.state = {
            classes: makeStyles({
                root: {
                  minWidth: 275,
                  maxWidth: 500,
                },
                bullet: {
                  display: 'inline-block',
                  margin: '0 2px',
                  transform: 'scale(0.8)',
                },
                title: {
                  fontSize: 48,
                },
                pos: {
                  marginBottom: 12,
                },
            }),
            value: 0,
            viewForm: false
        }
    }
    componentDidUpdate(prevProps) {
        const { value } = this.props;
        this.state.value = value;
    }

    render() {
        return(
            <div className='value-card'>
                <Card className={this.state.classes.root}>
                <CardContent>
                    <Typography className={this.state.classes.title} color="textSecondary" gutterBottom>
                    {this.props.name}
                    </Typography>
                    <Grid container justify="space-between" alignItems='flex-end'>  
                        <Typography  display="inline" align="left" variant="h2" component="h2">
                            {this.state.value} 
                        </Typography>
                        <Typography display="inline" align="right" variant="h6">
                            {this.props.unit}
                        </Typography>
                    </Grid>  
                </CardContent>
                </Card>
            </div>
    );
    }
}