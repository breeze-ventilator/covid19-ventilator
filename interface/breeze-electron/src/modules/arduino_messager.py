import serial
import socketio
import struct
import eventlet
from serial_interface import SerialInterface

# If no params reply with G

# TIME OUT SET TO NONE SO when reading, will only read once done.
ser = serial.Serial('/dev/cu.usbmodem14201', 9600, timeout=None)
sio  = socketio.Server()
app = socketio.WSGIApp(sio)
thread = None

PORT = 5000
serial_interface = SerialInterface(ser, sio)

@sio.on('connect')
def connect(sid, message):
  global thread
  global serial_interface
  print('connected')
  if thread == None:
    thread = sio.start_background_task(target=serial_interface.background_process)

@sio.on('parameterChange')
def set_params_to_send(sid, params):
  # TODO: EVERYTHING UNSIGNED ...
  global serial_interface
  print("Parameters from Pi:")
  for param_name, value in params.items():
    print(param_name, value)

  parameter_names = [
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
    "lowExpiratoryPressureAlarm"]
  
  byte_array = ord("P").to_bytes(1, byteorder="little", signed=False)
  
  checksum = (0).to_bytes(1, byteorder="little", signed=False)
  byte_array += checksum

  for name in parameter_names:
    byte_array += params[name].to_bytes(1, byteorder='little', signed=False)

  serial_interface.set_new_parameters(byte_array)


@sio.on('disconnect')
def disconnect(sid):
  print('disconnected')

print('hi')
eventlet.wsgi.server(eventlet.listen(('', PORT)), app, log_output=False)