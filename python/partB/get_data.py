def get_data(ser):
    response = ser.readline()
    temp_list = response.split(';')
    measures_dict = {"depth":temp_list[0], "ph":temp_list[1], "temperature":temp_list[2]}
    return measures_dict