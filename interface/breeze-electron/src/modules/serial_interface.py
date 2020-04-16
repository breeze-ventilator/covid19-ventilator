SLEEP_TIME = 0.1 # sec
LENGTH_OF_DATA_FROM_ARDUINO = 7
WELCOME_MESSAGE = 200

class SerialInterface:
  def __init__(self, ser):
    self.handshake_completed = False
    self.params_to_send = None
    self.need_to_send_params = False

    self.data_from_arduino = []
    self.data_counter = 0
    self.serial = ser
  
  def set_new_parameters(self, params_byte_array):
    self.params_to_send = params_byte_array
    self.need_to_send_params = True
    print('parameters set')

  def background_process(self):
    byte = self.serial.read(1)
    u_int8 = byte[0]

    if not self.handshake_completed:
      if (u_int8 == WELCOME_MESSAGE):
        print("RECEIVED WELCOME MESSAGE, NOW WRITING TO SERIAL")
        self.serial.write((WELCOME_MESSAGE).to_bytes(1, byteorder='little', signed=False))
        self.handshake_completed = True
    else:
      self.data_from_arduino.append(u_int8)
      self.data_counter += 1
      
      if self.data_counter == LENGTH_OF_DATA_FROM_ARDUINO:
        # Last data point from arduino ...
        
        # ship to frontend
        self.sio.emit('data', self.data_from_arduino)
        print(self.data_from_arduino)

        # And then check for sending to arduino back
        if self.need_to_send_params:
          print("Sending parameters...")
          self.serial.write(self.params_to_send)
          self.need_to_send_params = False
        else:
          # Otherwise write G.
          print("Sending G...")
          gs = [ord('G')] * 14 # sends array of Gs
          self.serial.write(bytes(gs))

        self.data_counter = 0
        self.data_from_arduino = []