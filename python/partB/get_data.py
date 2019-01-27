import i2c
import time

def depth():
    i2c.writeNumber(1)
    time.sleep(0.3)
    depth = i2c.readNumber()*(4.0/254.0)
    return (depth)

def ph():
    i2c.writeNumber(2)
    time.sleep(0.3)
    ph = i2c.readNumber()*(14.0/254.0)
    return (ph)

def temperature():
    i2c.writeNumber(3)
    time.sleep(0.3)
    temperature = i2c.readNumber()*(25.0/254.0)
    return (temperature)
