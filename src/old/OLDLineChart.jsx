import React, {Component} from 'react'
import ReactApexChart from 'react-apexcharts';
import ApexCharts from 'apexcharts';

// var lastDate = 0;
// var data = []
// var TICKINTERVAL = 1
// let X_AXIS_RANGE = 250
// function getDayWiseTimeSeries(baseval, count, yrange) {
//   var i = 0;
//   while (i < count) {
//     var x = baseval;
//     var y = Math.floor(Math.random() * (yrange.max - yrange.min + 1)) + yrange.min;

//     data.push({
//       x, y
//     });
//     lastDate = baseval
//     baseval += TICKINTERVAL;
//     i++;
//   }
// }
// getDayWiseTimeSeries(0, 10, {
//   min: 10,
//   max: 90
// })

// function getNewSeries(baseval, yrange) {
//   var newDate = baseval + TICKINTERVAL;
//   lastDate = newDate

//   for(var i = 0; i< data.length - 10; i++) {
//     // IMPORTANT
//     // we reset the x and y of the data which is out of drawing area
//     // to prevent memory leaks
//     data[i].x = newDate - X_AXIS_RANGE - TICKINTERVAL
//     data[i].y = 0
//   }

//   data.push({
//     x: newDate,
//     y: Math.floor(Math.random() * (yrange.max - yrange.min + 1)) + yrange.min
//   })
// }

function resetData(){
  // Alternatively, you can also reset the data at certain intervals to prevent creating a huge series 
  data = data.slice(data.length - 10, data.length);
}

let data = [];
let x = 0;
let X_AXIS_RANGE = 100;

export default class LineChart extends Component {
  constructor(props) {
    
    super(props);

    this.state = {
      series: [{
        data: data.slice()
      }],
      options: {
        chart: {
          id: 'realtime',
          height: 350,
          type: 'line',
          animations: {
            enabled: true,
            easing: 'linear',
            dynamicAnimation: {
              speed: 100
            },
            animateGradually: true,
          },
          toolbar: {
            show: false
          },
          zoom: {
            enabled: false
          }
        },
        dataLabels: {
          enabled: false
          adjustYScale
        stroke: {
          curve: 'smooth'
        },
        title: {
          text: 'Dynamic Updating Chart',
          align: 'left'
        },
        markers: {
          size: 0
        },
        xaxis: {
          range: 10,
          tickAmount: 5
        },
        yaxis: {
          max: 100
        },
        legend: {
          show: false
        },
      },
    
    
    };
  }
  componentDidMount() {
    window.setInterval(() => {
      // getNewSeries(lastDate, {
      //   min: 10,
      //   max: 90
      // })
      data.push({
        x: x,
        y: Math.floor(Math.random() * (90 - 10 + 1)) + 10,
      })
      x+=1
      
      ApexCharts.exec('realtime', 'updateSeries', [{
        data: data
      }])
    }, 100)
  }


  render() {
    return (
    <div id="chart">
      <ReactApexChart options={this.state.options} series={this.state.series} type="line" height={350} />
    </div>

    );
  }
}