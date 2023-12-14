from cs50 import get_string

text = ""
counter = grade = count_letters = count_sentences = 0
count_words = 1

# GET INPUT
while(text == ""):
    text = get_string("Text: ")

# MAIN LOOP
for char in text:
    # A - Z || a - z
    if char.isalpha():
        count_letters += 1

    # . || ! || ?
    if char in [".", "!", "?"]:
        count_sentences += 1

    # " "
    if char == " ":
        count_words += 1

    counter += 1

# CALC AND RESULTS
grade = round( 0.0588 * ( 100.0 * count_letters / count_words ) - 0.296 * ( 100.0 * count_sentences / count_words ) - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
