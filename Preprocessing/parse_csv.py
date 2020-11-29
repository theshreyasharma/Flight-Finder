import csv
flights_dict = {}
with open('openflights.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)

    for line in csv_reader:
        flights_dict[line[1]] = {line[6], line[7]} 

    for key, value in flights_dict.items():
        print (key, ' : ', value)