import csv
import sys
from collections import defaultdict


def longest_match(sequence, subsequence):
    """Returns the longest run of consecutive repeats of `subsequence` in `sequence`."""
    max_count = 0
    i = 0
    while i < len(sequence):
        count = 0
        while sequence[i:i+len(subsequence)] == subsequence:
            count += 1
            i += len(subsequence)
        max_count = max(max_count, count)
        i += 1
    return max_count


def main():
    # Check command-line arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py csv_file text_file")
        sys.exit(1)

    # File paths from command-line arguments
    csv_file = sys.argv[1]
    text_file = sys.argv[2]

    # Read the CSV file
    with open(csv_file, mode='r') as file:
        reader = csv.DictReader(file)
        str_names = reader.fieldnames[1:]  # STR names are the columns after the first one
        database = []
        for row in reader:
            person = {
                'name': row['name'],
                'str_counts': {str_name: int(row[str_name]) for str_name in str_names}
            }
            database.append(person)

    # Read the DNA sequence file
    with open(text_file, mode='r') as file:
        sequence = file.read().strip()

    # Compute the longest run of each STR in the DNA sequence
    str_counts = {}
    for str_name in str_names:
        str_counts[str_name] = longest_match(sequence, str_name)

    # Find a matching person in the database
    for person in database:
        if person['str_counts'] == str_counts:
            print(person['name'])
            return

    print("No match")

    
if __name__ == "__main__":
    main()
