
# Modify volume of a WAV file
![Screenshot 2024-01-18 132738](https://github.com/IntiToalombo/CS50/assets/95141129/e7c23942-0340-4c6a-acc4-7a0353da258f)

## Functionality
It is a simple program in C that changes the volume of an WAV file.
## Description
The program copies the header of the `input.wav` file treating each byte of it as a uint8_t value. in a new `output.wav f` file. In the same way it copies the audio sample treating it as an int16_t value.   
## How to use

**Run in CS50 Visual Stduio works space:** 

1. Access the [CS50 Visual Studio Code workspace](https://cs50.dev/)
2. Open the `volume.c` file in the workspace.
3. Save the file and run it using the CS50 IDE.

**Run Locally in VS Code on Windows:**
1. Install a compiler if you have not one already, follow this tutorial to do so [C compiler](https://code.visualstudio.com/docs/cpp/config-mingw).
2. Open the `volume.c` file in VS Code.
3. Save the file and compile it using `gcc volume.c -o volume`.
4. Run the `volume` executable file using the command `./volume input.wav output.wav 0.5` for a 50% volume decrease or `./volume input.wav output.wav 2.0` for a 100% volume increase.
5. Go to the directory where the `otuput.wav` file is stored and play it to verify if the audio in the file changes its volume.
