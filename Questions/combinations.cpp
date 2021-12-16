#include <iostream>
#include <vector>
using namespace std;
void helper(vector<vector<int>> &globalArr, vector<int> &curr, int n, int k, int index)
{
    if (curr.size() == k)
    {
        globalArr.push_back(curr);
        return;
    }
    else
    {
        for (int i = index; i <= n; i++)
        {
            curr.push_back(i);
            helper(globalArr, curr, n, k, i + 1);
            curr.pop_back();
        }
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> globalArr;
    vector<int> curr;
    helper(globalArr, curr, n, k, 1);
    return globalArr;
}