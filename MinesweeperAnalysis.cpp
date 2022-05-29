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
    std::cout << "Hello World!\n";
}
