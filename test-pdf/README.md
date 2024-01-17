# Check if a file is a PDF file

## Functionality
This simple C program determines whether a file is a PDF file by checking the first few bytes of the file's contents. PDF files have a specific signature that identifies them as valid PDF documents. The program reads the first four bytes of the file and compares them to the PDF file signature. If the first four bytes match the signature, the program prints a message indicating that the file is a PDF file. Otherwise, the program prints a message indicating that the file is not a PDF file.
## Description
This program can be used to quickly determine whether a file is a PDF file without having to open the file in Adobe Acrobat Reader or another PDF viewer. The program is also useful for testing whether a file is corrupt or invalid.

## How to use

**Run in CS50 Visual Studio Code Workspace:**

1. Access the [CS50 Visual Studio Code workspace](https://cs50.dev/)
2. Open the `pdf.c` file in the workspace
3. Save the file and run it using the CS50 IDE

**Run Locally in VS Code on Windows:**

1. Install the CS50 library which are two files `cs50.h` and `cs50.c`, also provided in this folder.
2. Install [C compiler](https://code.visualstudio.com/docs/cpp/config-mingw).
3. Open the `pdf.c` file in VS Code
4. Save the file and compile it using the C compiler
5. Place the `pdf` executable file and the file to be tested (test.pdf) in the same directory
6. Run the `pdf` executable file using the command `./pdf test.pdf` or `./pdf test.jpg`. Both files are provided in this folder.

**Note:** For recompiling the program, use the command `gcc pdf.c -o pdf cs50.c`. Remember that those two last files must be in the same directory as your program for it to work.

**Example usage:**

In you terminal write:
```console
./pdf test.pdf
```
or 
```console
./pdf test.jpg
```
If the file `test.pdf` is a valid PDF file, the program will print out:
```console
37
80
68
70
test.pdf is a PDF file.
```
If the file `test.jpg` is not a valid PDF file, the program will print out:
```console
255
216
255
224
test.jpg is not a PDF file.
```
**Additional notes**
* The program will print a warning message if it encounters an error while reading the file.
  
* The program will print an error message if the file does not exist.
