
# DNA matchig program
  ![image](https://github.com/IntiToalombo/CS50/assets/95141129/6d3f5802-8a15-4d74-8eb8-3c8595ceb329)

## Functionality
This Python program analyzes a DNA sequence against a database of DNA profiles to identify potential matches. It searches for Short Tandem Repeats (STRs) in the DNA sequence and compares them to the STRs found in the database. For instance [CODIS](https://www.fbi.gov/how-we-can-help-you/dna-fingerprint-act-of-2005-expungement-policy/codis-and-ndis-fact-sheet), the FBI’s DNA database, uses 20 different STRs as part of its DNA profiling process
## Features
* Reads DNA data from a CSV file containing profiles with names and STR values.
* Reads DNA sequence data from a text file.
* Finds the longest run of each STR in the DNA sequence.
* Compares the STR lengths found in the sequence to DNA profiles in the database.
* If a complete match is found, prints the name of the matching person from the database.
* Outputs "No match" if no match is found.
## How to use
```
python dna.py file_name.csv file_name.txt
```
Note: replace `file_name.csv` with the path to your CSV file containing DNA profiles, and `file_name.txt` with the path to your text file containing the DNA sequence.

## Dependenceies:
* Python 3
* `csv`module (included in standard library)
## Example usage:
1. In your terminal type `python dna.py databases/large.csv sequences/9.txt`.
2. You will see the following output if the DNA sequence matches a sequence in the databasee:
```
Draco
```
4. Otherwise if you type `python dna.py databases/large.csv sequences/3.txt` you will see:
```
No match
```
5. If you enter a different number of command-line arguments than expected (for example, by typing python dna.py), you will see the following:
```
Usage: python dna.py file_name.csv file_name.txt
```
## Acknowledgments
* This script is a solution for [problem set 6](https://cs50.harvard.edu/x/2024/psets/6/) of [CS50](https://cs50.harvard.edu/x/2024/) course powered by Harward University. 

