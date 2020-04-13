import serial
import socketio
import struct


# If no params reply with G

# TIME OUT SET TO NONE SO when reading, will only read once done.
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=None)
sio = socketio.AsyncClient()
port = 5000
length_of_data_from_arduino = 7

handshake_completed = False
params_to_send = None
need_to_send_params = False

data_from_arduino = []
data_counter = 0

@sio.on('parameterChange')
def set_params_to_send(params):
  # TODO: EVERYTHING UNSIGNED ...
  print("Parameters from Pi:")
  for param_name, value in params.items():
    print(param_name, value)

  int_array = []
  int_array.append(ord('P'))

  int_array.append(params["mode"])
  int_array.append(params["fiO2"])
  int_array.append(params["peep"])
  int_array.append(params["inspiratoryPressure"])
  int_array.append(params["sensitivity"])
  int_array.append(params["respiratoryRate"]) # uint8_t


  int_array.append(params["inspiratoryTime"]) # uint8_t
  int_array.append(params["flowCyclingOff"]) # unit8_t ???

  int_array.append(params["apneaTime"] * 10)
  int_array.append(params["riseTime"] * 10)
  int_array.append(params["highInspiratoryPressureAlarm"])
  int_array.append(params["lowExpiratoryPressureAlarm"])

  send_params_when_time = True
  params_to_send = bytearray(int_array)

def background_thread():
  sio.connect('http://localhost',port)
  while True:
    byte = ser.read(1)
    u_int8 = struct.unpack('B', byte)[0]

    if not handshake_completed:
      if(u_int8 == 1):
        ser.write(bytes([2]))
        handshake_completed = True
    elif data_counter == (length_of_data_from_arduino-1):
      # Last data point from arduino ...
      data_from_arduino.append(u_int8)

       # TO DO , we just finished so ship to frontend
      print(data_from_arduino)

      # And then check for sending to arduino back
      if need_to_send_params:
        ser.write(params_to_send)
      else:
        # Otherwise write G.
        ser.write(bytes([ord('G')]))

      data_counter = 0
    else:
      data_from_arduino.append(u_int8)
      data_counter += 1
