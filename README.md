# Number Puzzle

## What is it?
The program is written in C++ language using QT platform and QT Widget for the user interface. 

The Number Puzzle provides the player with 8 numbers, placed randomly. The player's task is to organize those numbers in the **ascending order**. 

Hint: The only way to move numbers around is by clicking on those numbers that are **adjacent to** the empty rectangle. The selected number will be switched with the empty rectangle. 

*I warn you, this puzzle is not easy!*

## Examples:

#### Example of the program

<img src="https://github.com/tphuong141607/YesCode-Number-Puzzle/blob/master/ProgramExample.png" width="30%">

#### What the program looks like when you solve the puzzle:

<img src="https://github.com/tphuong141607/YesCode-Number-Puzzle/blob/master/Example%20when%20puzzle%20solved.png" width="40%">

## How to run this program on your computer locally? (Macintosh operating systems)
#### Method 1: Using terminal
1. Download [Homebrew](https://brew.sh/) if you don't have it installed
2. Open terminal
3. Download QT by typing `brew install qt5` (I purpusely put QT version 5 to avoid any incompatible error) 
3. Type: `export PATH="/usr/local/opt/qt/bin:$PATH"`
5. Go to the `NumberPurzzle` directory
6. Type `qmake`
7. Type `make`
8. Type `./NumberPurzzle`

#### Method 2: Using Qt app
1. Download QT [here](https://www.qt.io/download)
2. Open the project on the QT application simply by double click on the `NumberPurzzle.pro` file
3. Run the program

Note: `NumberPurzzle.pro` file is in YesCode-Number-Puzzle/NumberPurzzle/NumberPurzzle.pro
