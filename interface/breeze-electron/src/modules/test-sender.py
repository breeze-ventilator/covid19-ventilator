import serial

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=None)

hadnshake_completed = False


while(True):
    if not hadnshake_completed:
        if ser.in_waiting:
            byte = ser.read(1)
            u_int8 = struct.unpack('B', byte)[0]
            print(u_int8)
            if u_int8 == 2:
                hadnshake_completed = True
        ser.write(bytes([1]))


