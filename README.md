# star-battles-solver

---IMPORTANT--
PLEASE VIEW README.md AS THE SOURCE TEXT

Star battles (aka Two Not Touch):
logic puzzle game with challenging solutions.

The goal of the game is to place a star in each row, column, and region.
Stars may not touch each other, meaning there may not be another star on the left, top, bottom, or right of an adjacent star.
Each puzzle is supposed to have only one solution.

The algorithm I have created using recursion solves the board a bit differently.
It solves a board given a .txt file, it takes in a row of numbers.

4 3
L 6
0 0
1 0
0 1
1 1
0 2
1 2
X 6
2 0
2 1
2 2
0 3
1 3
2 3

The first 2 are the number of rows and columns (respectively).
Afterwards, the zones are referred to with chars. 

The .txt file creates the following board:

LLX
LLX
LLX
XXX

L 6 describes the amount of squares that will belong to zone L.
The subsequent 6 inputs refer to the row and column of which square will belong to zone L.

0 0 belongs to L, 1 0 belongs to L, 0 1 belongs to L, and so on.

The program solves the entire board and gives every possible solution for one star in each row, column, and zone.

Unlike the original Star Battles game, this program doesn't require one star in each row, column, and zone,
but it does require that:

1. No two stars are in the same zone
2. No stars are adjacent to each other
3. No stars are placed in the same row or column as another star

To run, simply compile the file and run it, enter the input files (simple input files are given as custom1.txt, custom2.txt, and custom3.txt)
and the output file which you wish to create to store the possible solutions for your board.
