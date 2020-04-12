import React from "react";
import ReactDOM from "react-dom";
import App from "./components/App/App";
import StatusBar from './components/StatusBar/StatusBar';

ReactDOM.render(
  <React.StrictMode>
    <StatusBar />
    <App />
  </React.StrictMode>,
  document.getElementById("app")
);
