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
