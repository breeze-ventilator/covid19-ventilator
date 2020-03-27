import React from 'react';
import LineChart from './LineChart';
import './App.css';

function App() {
  return (
    <LineChart timeSeriesData={[5.0, 7.0, 10.0, -0.5, -1.0, 3, -5.0]} />
    // <div className="App">
    //   <header className="App-header">
    //     <img src={logo} className="App-logo" alt="logo" />
    //     <p>
    //       Edit <code>src/App.js</code> and save to reload.
    //     </p>
    //   </header>
    // </div>
  );
}

export default App;
