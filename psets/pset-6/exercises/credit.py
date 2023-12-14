from cs50 import get_int

card_number = left_count = right_count = 0

# GET INPUT
while(card_number == 0):
    card_number = str(get_int("Number: "))

# CARD VARIABLE SIZE
delimiter = card_len = len(card_number)

while(delimiter > 0):
    # NO MULTIPLIED BY 2
    left_count += int(card_number[delimiter - 1])

    # MULTIPLIED BY 2
    aux = int(card_number[delimiter - 2]) * 2

    if aux >= 10:
        right_count += (1 + (aux - 10))
    else:
        right_count += aux

    delimiter -= 2

# STORE RESULT
result = left_count + right_count

# VALIDATING RESULT [MOD(10) && VALID_NUMBERS && CARD_LEN]
if result % 10 == 0 and int(card_number[0]) == 3 and int(card_number[1]) == 4 or int(card_number[1]) == 7 and card_len == 15:
    print("AMEX")
elif result % 10 == 0 and int(card_number[0]) == 4 and card_len >= 13 and card_len <= 16:
    print("VISA")
elif result % 10 == 0 and int(card_number[0]) == 5 and int(card_number[1]) >= 1 and int(card_number[1]) <= 5 and card_len == 16:
    print("MASTERCARD")
else:
    print("INVALID")
