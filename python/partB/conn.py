from influxdb import InfluxDBClient

def conn():
	client = InfluxDBClient(host='localhost', port=8086)
	client.switch_database('entic')
	return client
