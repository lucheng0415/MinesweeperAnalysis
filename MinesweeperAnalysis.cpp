// MinesweeperAnalysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <optional>
#include <vector>
#include <tuple>

/* Debug information flag uncomment when needed */
//#define DEBUG

using namespace std;

/*
Function: GetUserInputs
Input: n/a
Output: a tuple of three int data represents: A B N
*/
tuple <int, int, int> GetUserInputs(void)
{
    int a, b, n = 0;

    cout << "Please enter A: ";
    cin >> a;
    cout << endl;
    cout << "Please enter B: ";
    cin >> b;
    cout << endl;
    cout << "Please enter N: ";
    cin >> n;
    cout << endl;

    return make_tuple(a, b, n);
}

/*
Function: SolutionProcessEngine
process the check always from the top left to the bottom
In case of having a valid solution, there must be at least
two lines of squares without mines
In: a,b size of the board
    n number of mines
Out: true/false indicates the calculation result
*/
bool SolutionProcessEngine(const int& a, const int& b, const int& n)
{
    int nLineFit, nLineFitLeft = 0;

    nLineFitLeft = n % b;
    nLineFit = (n / b) + (nLineFitLeft > 0);
#ifdef DEBUG
    cout << "a " << a << " b " << b << " n " << n << endl;
    cout << "nLineFit " << nLineFit << " nLineFitLeft " << nLineFitLeft << endl;
#endif
    if (nLineFitLeft == 0) /* The mines can be fit in nLineFit lines without leftovers
                              requires for at least two non-mines lines */
    {
        if ((a - nLineFit) > 1)
            return true;
        else
            return false;
    }
    else /* There are leftovers to the next line */
    {
        if ((b - nLineFit) < 2)
            return false;

        if ((a - nLineFitLeft) > 1) /* There are at least two squares containing a number */
            return true;
        else if ((a - nLineFitLeft) == 1 && (b - nLineFit) > 2)
            return true;
        else
            return false;
    }
}

/*
Function: SolutionValidation
Call the engine function to check if there is a valid solution with two directions
In: boardSizeA, boardSizeB size of the board
    nMines number of mines
Out: tuple <bool, bool>
    The first bool variable represents the result of detection
    The second one means the direction of the result, horizontally or vertically
*/
tuple <bool, bool> SolutionValidation(const int& boardSizeA, const int& boardSizeB, const int& nMines)
{
    if ((boardSizeA * boardSizeB) == (nMines + 1))
        return make_tuple(true, true);

    /* Verify the configuration horizontally */
    auto ret = SolutionProcessEngine(boardSizeA, boardSizeB, nMines);

    if (ret)
        return make_tuple(true, true);

    /* If not identified verify the configuration vertically */
    ret = SolutionProcessEngine(boardSizeB, boardSizeA, nMines);
    if (ret)
        return make_tuple(true, false);

    return make_tuple(false, false);
}

/*
Function: PrintBoard
Print out the configured board to the console
In: a 2-D vecotr arrary, size of the board
Out: void
*/
void PrintBoard(const vector<vector<int> >& board, const int& n, const int& m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] > 8)
                cout << "*" << " ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Function: LoadSymbolsToBoard
This function loads the mines and the numbers to the board
and if the last mines + 1 reach the boundary of the board
then move this mine to the next line.
Mines counting, if we have a square with position(i,j), then it has eight connections
1 - (i + 1, j + 1)
2 - (i + 1, j)
3 - (i + 1, j - 1)
4 - (i, j + 1)
5 - (i, j - 1)
6 - (i - 1, j + 1)
7 - (i - 1, j)
8 - (i - 1, j - 1)
The second part of this fuction counts the mines followed by this sequence.
In: a 2-D vecotr arrary, size of the board and nubmer of mines
Out: void
*/
void LoadSymbolsToBoard(vector<vector<int> >& board, const int& n, const int& m, int nMines)
{
    int cntMines = 0; /* A counter of numbers of mines placed */
#ifdef DEBUG
    cout << __func__ << " n " << n << " m " << m << " nMines " << nMines << endl;
#endif
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            /* As the max value of a number square is 8, so define the 9 to represent there is a mine */
            board[i][j] = 9;
            cntMines++;
            if (cntMines == nMines)
            {
                /* This to avoid the corner case, leave at least two spare squares to the end */
                if ((j + 2 == m) && (n * m != (nMines + 1)))
                {
                    board[i][j] = 0;
                    board[i + 1][0] = 9;
                }
                /* Hack to stop the loop */
                i = n;
                j = m;
            }
        }
    }

    cntMines = 0;
    for (int iStart = 0; iStart < n; iStart++)
    {
#ifdef DEBUG
        cout << __func__ << "Counting the row of iStart" << " " << iStart << endl;
#endif
        for (int jStart = 0; jStart < m; jStart++)
        {
            if (board[iStart][jStart] == 9) /* Skip the mine squares */
                continue;

            /* The three squares starts with iStart + 1 */
            if ((iStart + 1) < n)
            {
                if ((jStart + 1) < m && board[iStart + 1][jStart + 1] == 9)
                    cntMines++;

                if (board[iStart + 1][jStart] == 9)
                    cntMines++;

                if ((jStart - 1) >= 0 && board[iStart + 1][jStart - 1] == 9)
                    cntMines++;

            }

            /* The two squares starts with iStart */
            if ((jStart + 1) < m && board[iStart][jStart + 1] == 9)
                cntMines++;
            if ((jStart - 1) >= 0 && board[iStart][jStart - 1] == 9)
                cntMines++;

            /* The three squares starts with iStart - 1 */
            if ((iStart - 1) >= 0)
            {
                if ((jStart + 1) < m && board[iStart - 1][jStart + 1] == 9)
                    cntMines++;

                if (board[iStart - 1][jStart] == 9)
                    cntMines++;

                if ((jStart - 1) >= 0 && board[iStart - 1][jStart - 1] == 9)
                    cntMines++;

            }

            /* Assign the number of mines to the square and reset the counter */
#ifdef DEBUG
            cout << __func__ << "Counting in progress iStart" << " " << iStart << " " << "jStart" << " " << jStart << " cntMines " << cntMines << endl;
#endif
            board[iStart][jStart] = cntMines;
            cntMines = 0;
        }
    }
}

int main()
{
    string ans("");
    while (ans != "exit") {
        cout << "Hello ! Welcome to Cheng's Minesweeper Analyzer " << endl;
        cout << "A and B represents the size of the board" << endl;
        cout << "N means the number of mines" << endl;

        bool isInputsValid = false;
        tuple <int, int, int> inputs;

        while (!isInputsValid)
        {
            inputs = GetUserInputs();
            if ((get<0>(inputs) < 2 && get<1>(inputs) < 2) || get<2>(inputs) == 0 || get<2>(inputs) >= (get<0>(inputs) * get<1>(inputs)))
            {
                cout << "Wrong configuration detected ! Please check and reconfigure" << endl;
                cout << "The number of mines need to be less than the neumber of squares and must not be 0" << endl;
                cout << "The size of the game board must have at least two squares" << endl;
            }
            else
            {
                isInputsValid = true;
            }
        }

        int boardSizeA = get<0>(inputs);
        int boardSizeB = get<1>(inputs);
        int nMines = get<2>(inputs);

        auto [ret, dir] = SolutionValidation(get<0>(inputs), get<1>(inputs), get<2>(inputs));

        /* FIXME Magic swap to avoid direction of the vecrtor array */
        if (!dir) {
            boardSizeA = boardSizeA + boardSizeB;
            boardSizeB = boardSizeA - boardSizeB;
            boardSizeA = boardSizeA - boardSizeB;
        }

        if (ret) {
            cout << "There is valid mines configuration for " << get<0>(inputs) << " x " << get<1>(inputs) << " with " << get<2>(inputs) << " Mine(s)" << endl;

            /* Use vector to represent a 2D array */
            vector<vector<int> > board(boardSizeA, vector<int>(boardSizeB));

            /* Init the board to 0 */
            for (int i = 0; i < boardSizeA; i++)
            {
                for (int j = 0; j < boardSizeB; j++)
                {
                    board[i][j] = 0;
                }
            }
            // todo add board placement and print function here !
        }
        else
        {
            cout << "Impossible !" << endl;
        }

        cout << endl;
        cout << endl;
        cout << "Try again ? " << endl;
        cout << "Input exit to quit this program " << endl;
        cout << "Input any other key to run again " << endl;
        cout << "Please type: ";
        cin >> ans;
        cout << endl;
        cout << endl;
    }

    return 0;
}
