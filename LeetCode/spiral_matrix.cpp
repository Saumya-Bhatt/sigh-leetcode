#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int rowBegin = 0;
    int rowEnd = matrix.size() - 1;
    int colBegin = 0;
    int colEnd = matrix[0].size() - 1;

    while (rowBegin <= rowEnd && colBegin <= colEnd)
    {

        // traverse right
        for (int j = colBegin; j <= colEnd; j++)
        {
            ans.push_back(matrix[rowBegin][j]);
        }
        rowBegin++;

        //traverse down
        for (int i = rowBegin; i <= rowEnd; i++)
        {
            ans.push_back(matrix[i][colEnd]);
        }
        colEnd--;

        if (rowBegin <= rowEnd)
        {
            // traverse right
            for (int j = colEnd; j >= colBegin; j--)
            {
                ans.push_back(matrix[rowEnd][j]);
            }
        }
        rowEnd--;

        if (colBegin <= colEnd)
        {
            for (int i = rowEnd; i >= rowBegin; i--)
            {
                ans.push_back(matrix[i][colBegin]);
            }
        }
        colBegin++;
    }
    return ans;
}
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    vector<int> ans = spiralOrder(matrix);
    for (int i : ans)
    {
        cout << i << ' ';
    }
}