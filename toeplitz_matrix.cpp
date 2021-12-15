#include <vector>
using namespace std;
bool isToeplitzMatrix(vector<vector<int>> &matrix)
{
    for (int r = 0; r < matrix.size(); ++r)
    {
        for (int c = 0; c < matrix[0].size(); ++c)
        {
            if (matrix[r - 1][c - 1] != matrix[r][c])
                return false;
        }
    }
    return true;
}