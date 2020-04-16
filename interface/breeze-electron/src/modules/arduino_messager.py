#! /usr/bin/python3

"""Check for input every 0.1 seconds. Treat available input
immediately, but do something else if idle."""

import sys
import select
import time
import json

# files monitored for input
read_list = [sys.stdin]
timeout = 0.1 # seconds
last_work_time = time.time()

def print_out(msg):
  print(json.dumps(msg))
  sys.stdout.flush()

def treat_input(linein):
  global last_work_time
  data = json.loads(linein)
  print_out("Workin' it! {}".format(data))
  print_out('Done')
  last_work_time = time.time()

def idle_work():
  global last_work_time
  now = time.time()
  # do some other stuff every 2 seconds of idleness
  if now - last_work_time > 2:
    print_out('Idle for too long; doing some other stuff.')
    last_work_time = now

def main_loop():
  global read_list
  # while still waiting for input on at least one file
  while True: # could maybe stop when it hasn't received input for long enough
    ready = select.select(read_list, [], [], timeout)[0]
    if not ready:
      idle_work()
    else:
      for file in ready:
        line = file.readline()
        if line.rstrip(): 
          treat_input(line)

try:
    main_loop()
except KeyboardInterrupt:
  pass












# If no params reply with G

# TIME OUT SET TO NONE SO when reading, will only read once done.
# ser = serial.Serial('/dev/cu.usbmodem14201', 9600, timeout=None)

# serial_interface = SerialInterface(ser, sio)

  # If there's input ready, do something, else do something
  # else. Note timeout is zero so select won't block at all.

  


# def connect(sid, message):
#   print('connected')
#   if thread == None:
#     thread = sio.start_background_task(target=serial_interface.background_process)

# @sio.on('parameterChange')
# def set_params_to_send(sid, params):
#   # TODO: EVERYTHING UNSIGNED ...
#   global serial_interface
#   print("Parameters from Pi:")
#   for param_name, value in params.items():
#     print(param_name, value)

#   parameter_names = [
#     "mode",
#     "fiO2",
#     "peep",
#     "inspiratoryPressure",
#     "sensitivity",
#     "respiratoryRate",
#     "inspiratoryTime",
#     "flowCyclingOff",
#     "apneaTime",
#     "riseTime",
#     "highInspiratoryPressureAlarm",
#     "lowExpiratoryPressureAlarm"]
  
#   byte_array = ord("P").to_bytes(1, byteorder="little", signed=False)
  
#   checksum = (0).to_bytes(1, byteorder="little", signed=False)
#   byte_array += checksum

#   for name in parameter_names:
#     byte_array += params[name].to_bytes(1, byteorder='little', signed=False)

#   serial_interface.set_new_parameters(byte_array)


# @sio.on('disconnect')
# def disconnect(sid):
#   print('disconnected')

# print('hi')
# eventlet.wsgi.server(eventlet.listen(('', PORT)), app, log_output=False)