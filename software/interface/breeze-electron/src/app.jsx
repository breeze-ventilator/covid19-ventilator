import React from "react";
import ReactDOM from "react-dom";
import App from "./components/App/App";
// import StatusBar from './components/StatusBar/StatusBar';
import ReactNotification from 'react-notifications-component'
import 'react-notifications-component/dist/theme.css'
ReactDOM.render(
  <React.StrictMode>
    {/* <StatusBar /> */}
    <ReactNotification
        types={[
          {
            htmlClasses: ['notification-awesome'],
            name: 'awesome'
          }
        ]}
        isMobile={false}
      />
    <App />
  </React.StrictMode>,
  document.getElementById("app")
);
