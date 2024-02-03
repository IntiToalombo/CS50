# Readbility
## Functionality
This program calculates the approximate grade level needed to comprehend some text. This program outputs "Grade X" representing the grade level computed (rounded to the nearest integer). If the grade level is equal to or greater than 16, the program outputs "Grade 16+". If the grade is less than 1, the program outputs "Before Grade 1". For a detailed explanation visitit [Readability](https://cs50.harvard.edu/x/2024/psets/2/readability/).  

## How to use

**Run in CS50 Visual Studio Code Workspace:**

1. Access the [CS50 Visual Studio Code workspace](https://cs50.dev/)
2. Open the `readability.c` file in the workspace
3. Save the file and run it using the CS50 IDE

**Run Locally in VS Code on Windows:**

1. Install the CS50 library which are two files `cs50.h` and `cs50.c`, also provided in this folder.
2. Install [C compiler](https://code.visualstudio.com/docs/cpp/config-mingw).
3. Open the `readability.c` file in VS Code.
4. Save the file and compile it using the C compiler.
6. Run the `readability` executable file using the command `./readability` then introduce the text to be evaluated.

**Note:** For recompiling the program, use the command `gcc readability.c -o readability cs50.c`. Remember that `cs50.c` and `cs50.h`  files must be in the same directory as your program for it to work.
