import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './components/App/App';
import * as serviceWorker from './serviceWorker';
import StatusBar from './components/StatusBar/StatusBar';

ReactDOM.render(
  <React.StrictMode>
    <StatusBar batteryLevel={0.75} />
    <App />
  </React.StrictMode>,
  document.getElementById('root')
);

serviceWorker.unregister();
