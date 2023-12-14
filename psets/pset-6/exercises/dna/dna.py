from sys import argv, exit


def load_database(data) -> dict:
    # CREATING DICT
    people = dict()

    # SAVING HEADER
    header = data.readline()
    people["format"] = header.strip().split(",")

    # SAVING PEOPLE
    lines = data.readlines()

    for line in lines:
        person = line.strip().split(",")
        name = person[0]
        dna_seq = [int(dna) for dna in person[1:]]

        people[name] = dna_seq

    return people


def count_sequences(format: list = [], dna_sequence: str = "") -> list:
    seq_list = []

    # COUNT CONSECUTIVES SEQUENCES
    check_a = check_b = format[1:]

    count = 0

    # JUST WORKS.
    for acc, pre_seq in zip(check_a, check_b):
        while acc in dna_sequence:
            count += 1
            acc += str(pre_seq)

        seq_list.append(count)
        count = 0

    return seq_list


def main() -> None:
    # ARGV HANDLING
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # READING CSV DATABASE
    with open(argv[1], "r") as database:
        # CREATING DICT
        people = load_database(database)
        # CLOSING FILE
        database.close()

    # READING PERSON DNA
    with open(argv[2], "r") as sequence:
        # READING SEQUENCE
        dna = sequence.readline().strip()
        # CLOSING FILE
        sequence.close()

    # COUNT SEQUENCES
    sequences = count_sequences(people["format"], dna)

    # FINDING PERSON W/ LINEAR SEARCH
    found = 0
    for key, item in people.items():
        if key == "format":
            continue

        if item == sequences:
            found = 1
            print(key)

    if not found:
        print("No match")


if __name__ == "__main__":
    main()
