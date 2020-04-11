import serial
import socketio.CLient()

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

def background_thread():
    while True:
        data = ser.readline()
        if len(data) > 0:
            socketio.emit('message', {'data': data})
    ser.close()
