#include <iostream>
#include <vector>
#include <set>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    set<int> row_set, col_set;
    int rows = matrix.size();
    int columns = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] == 0)
            {
                row_set.insert(i);
                col_set.insert(j);
            }
        }
    }
    set<int>::iterator it;
    for (it = row_set.begin(); it != row_set.end(); it++)
    {
        for (int i = 0; i < columns; i++)
        {
            matrix[*it][i] = 0;
        };
    };
    for (it = col_set.begin(); it != col_set.end(); it++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix[j][*it] = 0;
        };
    };
}
int main()
{
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> matrix;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    setZeroes(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}