# Minesweeper one-click solution Analyzer
A windows application to find an 1-click solution

# Requirements abstraction
In this task, we are trying to demonstrate an analyzer of one-click solutions for a popular game Minesweeper,  the target software needs to be run on Windows command line as a console application.

The input parameters are the size of the board(A x B), the number of mines (N).

The output is, if there is a valid one-click solution then the application should print the mine configuration associated with the click position, otherwise print “Impossible”.

The application should allow the user to quit and restart the analysis process.

# Rules recapture
If we have a 4 x 4 board, and there are 3 mines, assume the game gives us a following configuration:
.  .  *  .  
.  .  *  .
.  .  *  .
.  .  .  .
The “ * ” denotes a square containing a mine, and the number representing the mine(s) surrounding that square are hidden, the game displays it with a “ . ” . 

If the user clicks on the square which contains a mine, then the game is over and you lose it. If the user clicks the square which contains a number equal to “0” then the game starts to reveal the squares around it recursively until it reaches the first square that is directly next to a mine(s) inclusively.

Let’s say the user click the left bottom square as we know the mines configuration, the board should display like this:
0  2  *   . 
0  3  *   .
0  2  *   .
C  1  .   .
Obviously, in order to win the game, the user needs to click the remaining “ . ” one by one to win the game.

