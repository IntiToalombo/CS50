import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) == 3:
        # print(sys.argv)
        path_people = sys.argv[1]
        path_sequence = sys.argv[2]
    else:
        print("Usage: python dna.py file_name.csv file_name.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    data_base = []  # List of dictionaries as data base
    with open(path_people, 'r') as file:
        data = csv.DictReader(file)  # read csv file into a dictionary format
        for row in data:
            data_base.append(row)
        # print(data_base)
        subsequence_strs = list(data_base[0].keys())[1:]  # create a list of subsequence STRs

    # TODO: Read DNA sequence file into a variable
    sequence = ""  # String of DNA sequences
    with open(path_sequence, 'r') as file:
        sequence = file.read()  # create the large sequence into a string
        # print(sequence)

    # TODO: Find longest match of each STR in DNA sequence
    result = {}
    for subsequence in subsequence_strs:
        result[subsequence] = str(longest_match(sequence, subsequence)
                                  )  # convert returned value to str
    # TODO: Check database for matching profiles
    # Iterate over dictionary
    for suspect in data_base:
        # Create a dictionary without name
        suspect_without_name = {key: suspect[key] for key in suspect if key != "name"}
        # Comparing if result and suspect without name matches
        if suspect_without_name == result:
            print(suspect["name"])
            break
    else:
        print("No match")
    return 0


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
