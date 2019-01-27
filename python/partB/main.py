from conn import conn
from influx_insert import influx_insert
import get_data
import i2c
import time

def main():
    client = conn()
    
    try:
        while 1:
            influx_insert(client, get_data.depth(), "depth")
            #time.sleep(0.1)
            influx_insert(client, get_data.ph(), "ph")
            #time.sleep(0.1)
            influx_insert(client, get_data.temperature(), "temperature")
            #time.sleep(0.1)
            
    except KeyboardInterrupt:
        print ("Exiting program...")
        client.close()
        
main()
