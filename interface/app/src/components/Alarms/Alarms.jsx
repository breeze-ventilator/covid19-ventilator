import React from 'react';
import ValueChart from '../ValueChart/ValueChart';

import ParameterInput from '../ParameterInput/ParameterInput'
import Box from '@material-ui/core/Box';
import Container from '@material-ui/core/Container';
import Grid from '@material-ui/core/Grid';
import Button from '@material-ui/core/Button';

export default class Vitals extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <Box component="span" m={1}>
      <Container>
          <Grid container alignItems="stretch"justify="space-between" spacing={3} direction="column">
              <Grid item xl={6} md={6} sm={12} xs={12}>
                <Grid container justify="space-evenly" spacing={3} direction="row">
                </Grid>
              </Grid>
              <ParameterInput parameterName="Patient Body Weight" startingValue={80} step={2} min={21} max={100} unit={"%"}/>
              {/*TODO: Make the lower parameters appear only once the weight has been entered, and change startingValue accordingly. */}
              <br></br><br></br>
              <ParameterInput parameterName="Low Volume Bound" startingValue={80} step={2} min={21} max={100} unit={"%"}/>
              <ParameterInput parameterName="High Volume Bound" startingValue={80} step={2} min={21} max={100} unit={"%"}/>
              <br></br><br></br>
              <ParameterInput parameterName="Low FiO2 Bound" startingValue={80} step={2} min={21} max={100} unit={"%"}/>
              <ParameterInput parameterName="High FiO2 Bound" startingValue={80} step={2} min={21} max={100} unit={"%"}/>

              <Grid item text-align="center" xl={6} md={6} sm={12} xs={12}>
                <Button className="setParametersButton" variant="contained" align="center" color="primary">
                  Save Changes
                </Button>
              </Grid>
        </Grid>
      </Container>
    </Box>

    );
  }
}
