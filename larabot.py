#!/usr/bin/env python


import serial
import sys


class PanTilt(object):
    term = '\r'
    limit = 180    # 180 degree limit

    def __init__(self, port):
        self.serial = serial.Serial(port)
        self.current_pan = self.current_tilt = 0
        self.tilt(140)
        self.pan(90)

    def tilt(self, val):
        self.set_tilt(self.current_tilt + val)

    def pan(self, val):
        self.set_pan(self.current_pan + val)

    def set_tilt(self, pos):
        if pos < 0 or pos > PanTilt.limit:
            return
        self.command(0, pos)
        self.current_tilt = pos

    def set_pan(self, pos):
        if pos < 0 or pos > PanTilt.limit:
            return
        self.command(1, pos)
        self.current_pan = pos

    def command(self, axis, position):
        return self.serial.write("{},{}{}".format(axis, position, PanTilt.term))


def main():
    controller = PanTilt("/dev/ttyACM0")
    controller.pan(int(sys.argv[1]))
    controller.tilt(int(sys.argv[2]))


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print >>sys.stderr, "Usage: {} <pan> <tilt>".format(sys.argv[0])
        sys.exit(1)
    main()
