# Recovering deleted data
## Functionality 
Digital cameras tend to store data contiguously on memory cards,  it means that each photo is stored inmediately after the previously taken photo. Hence, the start of a JPEG file's header demarks the end of another. These cameras only write to those cards in "blocks" of 512 Bytes as a result a wasted spaces which is called "slack space" remains on card. Forenseic investigators then often look at space for remmants of suspicious data.
## Description 
It is a C programm that recover photos (JPEGS) that has been deleted from a memory card. 
## How to use
**Run in CS50 Visual Studio Code Workspace:**

1. Access the [CS50 Visual Studio Code workspace](https://cs50.dev/)
2. Open the `recover.c` file in the workspace.
3. Save the file and run it using the CS50 IDE.

**Run Locally in VS Code on Windows:**
1. Install [C compiler](https://code.visualstudio.com/docs/cpp/config-mingw).
2. Open the `recover.c` file in VS Code
3. Save the `recover.c` and compile it using the C compiler.
4. Run the `recover` executable file using the command `./recover card.raw`, then you will visualize 50 recovered images.

**Note:** both files `recover.c` and `card.raw` must be stored in the same directory.
## Cleaning directory
Execute the command below to delet all JPEGs in your current working directory.
```
rm *.jpg
 ```
or 
```
rm -f *.jpg
```
To delete without confirmation for each file.
