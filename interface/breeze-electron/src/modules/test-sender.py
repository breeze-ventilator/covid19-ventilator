import eventlet
import socketio

sio = socketio.Server()
app = socketio.WSGIApp(sio)
PORT = 5000
thread = None

def background():
    while True:
        sio.sleep(.1)
        print("BACKGROUND!")
        pass

@sio.on('connect')
def connect(sid, environ):
    global thread
    print('connect ')
    if thread == None:
        pass
        thread = sio.start_background_task(target=background)

@sio.on('parameterChange')
def parameterChange(sid, message):
    print(message)


@sio.on('disconnect')
def disconnect(sid):
    print('disconnect ')

if __name__ == '__main__':
    eventlet.wsgi.server(eventlet.listen(('', PORT)), app, log_output=False)