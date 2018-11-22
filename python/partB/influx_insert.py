from datetime import datetime
import time

# Measure types: depth, temperature, ph.
def influx_insert(client, value, measure):
	date = datetime.utcnow()
	json_body = [
    {
        "measurement": measure,
        "time": str(date),
        "fields": {
            "value": value
        }
    }]

	client.write_points(json_body)
	time.sleep(0.5)
