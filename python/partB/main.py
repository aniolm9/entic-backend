from conn import conn
from influx_insert import influx_insert
from get_data import get_data

def main():
	port = ""
	client = conn()
	
	while 1:
		measures_dict = get_data(port)
		for measure, value in measures_dict.items():
			influx_insert(client, value, measure)

	client.close()
	#ser.close()

main()
