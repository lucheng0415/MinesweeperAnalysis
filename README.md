# Minesweeper one-click solution Analyzer
A windows application to find an 1-click solution

# Requirements abstraction
In this task, we are trying to demonstrate an analyzer of one-click solutions for a popular game Minesweeper,  the target software needs to be run on Windows command line as a console application.

The input parameters are the size of the board(A x B), the number of mines (N).

The output is, if there is a valid one-click solution then the application should print the mine configuration associated with the click position, otherwise print “Impossible”.

The application should allow the user to quit and restart the analysis process.

# Rules recapture
If we have a 4 x 4 board, and there are 3 mines, assume the game gives us a following configuration:

.   .   *   .

.   .   *   .

.   .   *   .

.   .   .   .

The “ * ” denotes a square containing a mine, and the number representing the mine(s) surrounding that square are hidden, the game displays it with a “ . ” . 

If the user clicks on the square which contains a mine, then the game is over and you lose it. If the user clicks the square which contains a number equal to “0” then the game starts to reveal the squares around it recursively until it reaches the first square that is directly next to a mine(s) inclusively.

Let’s say the user click the left bottom square as we know the mines configuration, the board should display like this:

0   2   *    . 

0   3   *    .

0   2   *    .

C   1   .    .

Obviously, in order to win the game, the user needs to click the remaining “ . ” one by one to win the game.

# Analysis
The fewer mines configured in the board, the easier the user could win in 1 click, based on the rules, in order to make the square revealing process go as far as it could be, all the squares which contain a “ 0 ” must be connected to each other and there are eight neighbors associated with one square.

And there is one special case if the number of mines equal to the size of the board - 1, the one-click solution always exists as there is only one square the user can click.

Let’s review some of the configuration for further investigation.

A = 4, B = 4, N = 1

0 1 1 1

0 1 * 1

0 1 1 1

0 0 0 0

With this configuration, if the user click any square which contains a “ 0 ”, there will be 3 squares (Bold) can’t be revealed in the right up corner, let’s reconfigure the position of mine to the up right corner as below:

0 0 1 *

0 0 1 1

0 0 0 0

0 0 0 0

With this change, if the user clicks any of the squares which contains a “ 0 ”, then you win the game.

A = 4, B = 4, N = 2
Based on the previous mines configuration analysis, so in this case let’s put the 2 mines next to the boundary of the board as below:

1 *  2  *

1 1 0 1

0 0 0 0

0 0 0 0

This configuration can’t be resolved by 1 click, as after the user clicks any squares with “ 0 ”, there is still one square left which is located on the top-left(Bold).  Let’s reconfigure the mines by connecting them together as below:

0 1 *  *

0 1 2 2

0 0 0 0

0 0 0 0

With this configuration, the one-click solution is available by clicking any of the squares containing a “ 0 ”.

With the investigation of these two examples, the squares containing a number must be connected with at least one square containing a “ 0 ”, and the mines need to be configured next to each other and besides the boundary of the board.

The minimum size of the board that have one-click solution

A = 2, B = 1, N = 1
Obviously the one-click solution is available as there is only one square the user can click.

A = 2, B = 2, N = 1
As there is only one mine in this case, the configuration shown as below:

[*  1]

[1  1]

There is no one-click solution as the user needs to reveal the three squares one by one.

A = 2, B = 2, N = 2

[*  *]

[2  2]

There is no one-click solution as the user needs to reveal the two squares one by one. So for the 2 x 2 board the only valid mine configuration is N = 3. 

# Conclusion

Based on the analysis, the essential condition of a mines configuration should comply with the following rules:
* All the mines must be connected with the squares which are not contain a mine, or are next to the boundary;
* All squares marked as containing a number must be connected with a square containing “0”;
* All squares containing a “0” must be connected. 

# Software Solution and Design

The valid inputs verification
If A and B both less than 2 then inputs are invalid, as there is no game that only has one square.
If the board size (A x B) equals to the number of mines (N) or N equals to 0 then inputs are invalid.

Finding the valid one-click configuration
If the size of the board (A x B) equal to (N - 1), then directly print the mine's configuration.
If A and B are equal, then calculate how many lines with length of A needed to place all the mines, then check if there are two lines left at least, if yes then there is a valid one-click configuration otherwise there isn’t.
If A and B are not equal,  then calculate how many lines with the length of the shorter between A and B to place all the mines, then check if there are two lines left at least,  if yes then there is a valid one-click configuration otherwise there isn’t.

There are four main fucntions needs to be implemented:
* GetUserInputs: the user inputs, ask the user to input the size of the board and the numbers of the mines want to check.
* SolutionValidation: the core process engine, to identify if there is a valid board configuration.
* LoadSymbolsToBoard: writing the configuration to the required size of the board.
* PrintBoard: print the calculated result to the console.

Use std::vector to represent a 2D array which gives a flexible size defination: vector<vector<int> > board(boardSizeA, vector<int>(boardSizeB)) 


# Reference
Minesweeper. (n.d.). Minesweeper. Retrieved May 29, 2022, from https://minesweeper.online/

