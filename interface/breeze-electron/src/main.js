const { app, BrowserWindow, ipcMain } = require('electron');

const path = require('path');
const {PythonShell} = require('python-shell');

// Handle creating/removing shortcuts on Windows when installing/uninstalling.
if (require('electron-squirrel-startup')) { // eslint-disable-line global-require
  app.quit();
}

const createWindow = () => {
  // Create the browser window.
  const mainWindow = new BrowserWindow({
    width: 480,
    height: 800,
    webPreferences: {
      nodeIntegration: true
    }
  });

  // and load the index.html of the app.
  mainWindow.loadURL(MAIN_WINDOW_WEBPACK_ENTRY);

  // Open the DevTools.
  mainWindow.webContents.openDevTools();
  var pyScript = `import json
import sys
import select
import serial

FRONTEND_READ_TIMEOUT = 0.1 # sec
LENGTH_OF_DATA_FROM_ARDUINO = 7
WELCOME_MESSAGE = 200

class SerialInterface:
  def __init__(self):
    self.handshake_completed = False
    self.params_to_send = None
    self.need_to_send_params = False

    self.data_from_arduino = []
    self.data_counter = 0
    self.read_list = [sys.stdin]
    self.parameter_names = [
      "mode",
      "fiO2",
      "peep",
      "inspiratoryPressure",
      "sensitivity",
      "respiratoryRate",
      "inspiratoryTime",
      "flowCyclingOff",
      "apneaTime",
      "riseTime",
      "highInspiratoryPressureAlarm",
      "lowExpiratoryPressureAlarm"
      ]
    self.port = '/dev/cu.usbmodem14101' # '/dev/ttyACM0'
    # self.port = '/dev/ttyACM2'
    self.serial = None
    self.start_serial()
    self.debug_mode = True
  
  def start_serial(self):
    self.serial = serial.Serial(self.port, 9600, timeout=None)
  
  def get_data_from_app(self):
    ready = select.select(self.read_list, [], [], FRONTEND_READ_TIMEOUT)[0]
    return ready

  def send_to_app(self, data):
    print(json.dumps(
      {
        "type": "data",
        "data": data,
      }))
    sys.stdout.flush()
  
  def debug(self, message):
    if self.debug_mode:
      print(json.dumps(
        {
          "type": "debug",
          "data": message
        }))
      sys.stdout.flush()
    else:
      return
    
  def set_new_parameters_from_byte_array(self, params_byte_array):
    self.params_to_send = params_byte_array
    self.need_to_send_params = True
    self.debug('parameters set')
  
  def set_new_parameters(self, line):
    params = json.loads(line)
    self.debug(params)
    params_byte_array = ord("P").to_bytes(1, byteorder="little", signed=False)
    
    checksum = (0).to_bytes(1, byteorder="little", signed=False)
    params_byte_array += checksum

    for name in self.parameter_names:
      params_byte_array += params[name].to_bytes(1, byteorder='little', signed=False)

    self.set_new_parameters_from_byte_array(params_byte_array)

  def main_loop(self):
    ready = self.get_data_from_app()
    if not ready:
      self.read_from_serial()
    else:
      for file in ready:
        line = file.readline()
        if line.rstrip(): 
          self.set_new_parameters(line)

  def read_from_serial(self):
    byte = self.serial.read(1)
    u_int8 = byte[0]

    if not self.handshake_completed:
      if (u_int8 == WELCOME_MESSAGE):
        self.debug("RECEIVED WELCOME MESSAGE, NOW WRITING TO SERIAL")
        self.serial.write((WELCOME_MESSAGE).to_bytes(1, byteorder='little', signed=False))
        self.handshake_completed = True
    else:
      self.data_from_arduino.append(u_int8)
      self.data_counter += 1
      
      if self.data_counter == LENGTH_OF_DATA_FROM_ARDUINO:
        # Last data point from arduino ...
        
        # ship to frontend
        self.send_to_app(self.data_from_arduino)

        # And then check for sending to arduino back
        if self.need_to_send_params:
          self.debug("Sending parameters...")
          self.serial.write(self.params_to_send)
          self.need_to_send_params = False
        else:
          # Otherwise write G.
          self.debug("Sending G...")
          gs = [ord('G')] * 14 # sends array of Gs
          self.serial.write(bytes(gs))

        self.data_counter = 0
        self.data_from_arduino = []

s_interface = SerialInterface()

def main():
  while True:
    s_interface.main_loop()

try:
  main()
except KeyboardInterrupt:
  pass`;
  // var pyshell = PythonShell.runString(pyScript, null, function (err) {
  //   if (err) throw err;
  //   console.log('finished');
  // });
  var pyshell = new PythonShell('/Users/raffihotter/Code/covid19-ventilator/interface/breeze-electron/src/modules/arduino_messager.py');
  // pyshell.send({hello: 5, goodbye: 6});

  pyshell.on('message', function(message) {
    console.log(message, new Date().getTime());
    let jsonMsg = JSON.parse(message);
    mainWindow.webContents.send('newData', jsonMsg)
  })

  ipcMain.on('newParams', (event, arg) => {
    pyshell.send(JSON.stringify(arg));
  })
};

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on('ready', createWindow);

// Quit when all windows are closed.
app.on('window-all-closed', () => {
  // On OS X it is common for applications and their menu bar
  // to stay active until the user quits explicitly with Cmd + Q
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', () => {
  // On OS X it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow();
  }
});