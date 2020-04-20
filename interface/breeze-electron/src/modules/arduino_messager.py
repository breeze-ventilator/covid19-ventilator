#! /usr/bin/python3

"""Check for input every 0.1 seconds. Treat available input
immediately, but do something else if idle."""

from serial_interface import SerialInterface

# s_interface = SerialInterface()

def main():
	while True:
		# s_interface.main_loop()
		a = 1

try:
  main()
except KeyboardInterrupt:
  pass