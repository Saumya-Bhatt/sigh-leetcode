#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<string> &queens, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (queens[i][col] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (queens[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (queens[i][j] == 'Q')
            return false;
    }
    return true;
}
void helper(vector<vector<string>> &globalArr, vector<string> queens, int row, int n)
{
    if (row == n)
    {
        globalArr.push_back(queens);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(queens, row, col, n))
        {
            queens[row][col] = 'Q';
            helper(globalArr, queens, row + 1, n);
            queens[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> globalArr;
    vector<string> queens(n, string(n, '.'));
    helper(globalArr, queens, 0, n);
    return globalArr;
}