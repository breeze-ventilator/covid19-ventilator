import React from 'react';
import ParameterInput from '../ParameterInput/ParameterInput'
import Box from '@material-ui/core/Box';
import Container from '@material-ui/core/Container';
import Grid from '@material-ui/core/Grid';
import Card from '@material-ui/core/Card';


export default class Settings extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <Box component="span" m={1}>
        <Container>
          <Grid>
            <Grid container justify="left" spacing={1} direction="row">

              <Card>
              <div align="center">
              FiO2
              </div>
              <ParameterInput startingValue={80} step={2} min={21} max={100} unit={"%"}/>
              </Card>

              <Card>
              <div align="center">
              PEEP
              </div>
              <ParameterInput startingValue={20} step={2} unit={"cmH20"}/>
              </Card>
        </Grid>

          <Grid container justify="right" spacing={1} direction="row">

            <Card>
              <div align="center">
              Sensitivity
              </div>
              <ParameterInput startingValue={80} step={2} />
            </Card>

            <Card>
              <div align="center">
              Pressure support point
              </div>
              <ParameterInput startingValue={20} step={2} unit={"cm H20"} />
            </Card>

            <Card>
              <div align="center">
              Inspiratory Time
              </div>
              <ParameterInput startingValue={0.3} step={2} unit={"L"} />
            </Card>
          </Grid>
          </Grid>
        </Container>
      </Box>

    );
  }
}
