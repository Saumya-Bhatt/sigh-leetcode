#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{
    vector<vector<int>> ans;
    for (vector<int> row : image)
    {
        reverse(row.begin(), row.end());
        for (int i = 0; i < row.size(); i++)
        {
            row[i] ^= 1;
        }
        ans.push_back(row);
    }
    return ans;
}