from cs50 import get_int

height = -1

# GET INPUT FROM USER
while(height <= 0 or height >= 9):
    height = get_int("Height: ")

# PRINTING STAIR
for i in range(height):
    # ----------1st Figure----------
    # PRINT SPACES
    for spaces in range(height - i - 1):
        print(" ", end="")

    # PRINT #
    for character in range(i + 1):
        print("#", end="")

    # SEPARATE FIGURES
    print("  ", end="")

    # ----------2nd Figure----------
    for character in range(i + 1, 0, -1):
        print("#", end="")

    # BREAK LINE '\n'
    print("")
