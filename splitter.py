#!usr/local/bin/python

content = [line.rstrip('\n') for line in open('lon_data')]

lon_dict = {}

for line in content:
        items = line.split()
        key, values = items[0], items[1:]
        lon_dict[key] = values


content2 = [line.rstrip('\n') for line in open('lat_data')]

lat_dict = {}

for line in content2:
        items = line.split()
        key, values = items[0], items[1:]
        lat_dict[key] = values

islands_data = [line.rstrip('\n') for line in open('islands_data')]

for line in islands_data:
        items = line.split()
        lat, lon1, lon2 = items[0], items[1], items[2]
        print lat_dict[lat],lon_dict[lon1],lon_dict[lon2]
