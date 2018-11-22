from conn import conn
from influx_insert import influx_insert
from get_data import get_data
from ser import ser

def main():
	client = conn()
	ser = ser()
	
	try:
		while 1:
			measures_dict = get_data(ser)
			for measure, value in measures_dict.items():
				influx_insert(client, value, measure)

	except KeyboardInterrupt:
		print ("Exiting program...")
		client.close()
		ser.close()

main()
