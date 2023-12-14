import csv

titles = set()

with open("forms-response.csv", "r") as file:
    #1reader = csv.reader(file)
    reader = csv.DictReader(file)
    #1next(reader)
    for row in reader:
        #1print(row[1])
        titles.add(row["title"].strip().upper())

for title in sorted(titles):
    print(title)
