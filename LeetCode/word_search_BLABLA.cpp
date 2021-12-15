#include <iostream>
#include <vector>
using namespace std;
bool exist(vector<vector<char>> &board, string word)
{
}
int main()
{
    int rows, columns;
    cin >> rows, columns;
    vector<vector<char>> board;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            char temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }
    string word;
    cin >> word;
    cout << exist(board, word);
}