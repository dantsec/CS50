import csv

titles = dict()

with open("forms-response.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()

        if not title in titles:
            titles[title] = 0

        titles[title] += 1

def f(title):
    return titles[title]

#sorted(titles, key=lambda title: titles[title], reverse=True):
for title in sorted(titles, key=f, reverse=True):
    print(f"{title} - {titles[title]}")
