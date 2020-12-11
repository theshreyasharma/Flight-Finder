'''
Python parser for selecting important data from original openflights.csv (name, latitude, longitude). Writes to another CSV file.
'''

'''
import csv
import json
flights_dict = {}
with open('openflights.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for line in csv_reader:
        flights_dict[line[1]] = [line[6], line[7]]

with open('openflightsformatted.csv', 'w') as csv_file_:
    #writer = csv.writer(csv_file_)
    for key, value in flights_dict.items():
        csv_file_.write(key)
        csv_file_.write(',')
        for i, val in enumerate(value):
            csv_file_.write(val)
            if i < len(value)-1: #trailing comma
                csv_file_.write(',')
        csv_file_.write('\n')
'''
        