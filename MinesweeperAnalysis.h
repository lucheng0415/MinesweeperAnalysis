#pragma once
#include <tuple>
#include <vector>
using namespace std;

tuple <bool, bool> SolutionValidation(const int& boardSizeA, const int& boardSizeB, const int& nMines);
void LoadSymbolsToBoard(vector<vector<int> >& board, const int& n, const int& m, int nMines);