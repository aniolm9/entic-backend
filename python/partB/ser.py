import serial

def ser():
    ser = serial.Serial("", 9600, timeout=1)
    ser.open()