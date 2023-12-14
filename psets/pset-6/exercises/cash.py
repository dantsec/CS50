from cs50 import get_float

cash = 0
total = 0

# GET INPUT
while cash <= 0:
    cash = get_float("Change owed: ")

# AVOID FLOAT PRECISION ISSUES
cash_in_cents = int(cash * 100)

# GET INTEGER PART OF DIVISION
total += cash_in_cents // 25
# GET INTEGER REST OF DIVISION
cash_in_cents %= 25

total += cash_in_cents // 10
cash_in_cents %= 10

total += cash_in_cents // 5
cash_in_cents %= 5

total += cash_in_cents

# PRINT TOTAL OF COINS
print(total)
