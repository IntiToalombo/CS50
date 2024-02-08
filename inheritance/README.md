# Blood Type Inheritance
## Functionality
This program simulates the [inheritance of blood types](https://www.youtube.com/watch?v=xfZhb6lmxjk) across multiple generations in family tree.
## Features:
* Generates a family tree with up to 10 generations(confifurable by the user).
* Assigns random blood types alleles (A, B, or O) to each individual based on their parent's alleles.
* Prints the family tree, indicating each generation's generation and blood type.
## Dependencies:
* `stdio.h`
* `stdlib.h`
* ` time.h`
* `string.h`
## How to use:
1. Clone the repository or download the code.
2. Compile the code: `gcc inheritance.c -o inheritance`
3. Run the executable: `./inheritance`
4. The program will prompt you the desired number of generations(max 10).
5. The generated family tree with inheritance blood type will be printed to the console.
## Code Structure:
* `person.h`: Defines the `person` structure which contains information about each family member.
* `inheritance.c`: Main function for creating, printing, and freeing the family tree.
* `random_allele.c`: Generates a random blood type allele.
* `generation_number.c`: Gets the number of generations from the user and validates it.
## Note:
* The code uses dynamically allocated memory for user input improving robustness.
* This is a simplified simulation for blood type inheritance, it needs to be improved to account for all real-world scenarios.

  
