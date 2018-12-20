import i2c

def depth():
    i2c.writeNumber(1)
    time.sleep(0.2)
    depth = i2c.readnumber()*(4/254)
    return (depth)

def ph():
    i2c.writeNumber(2)
    time.sleep(0.2)
    ph = i2c.readnumber()*(14/254)
    return (ph)

def temperature():
    i2c.writeNumber(3)
    time.sleep(0.2)
    temperature = i2c.readnumber()*(25/254)
    return (temperature)
