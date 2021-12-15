#include <iostream>
#include <vector>
using namespace std;
void helper(vector<int> &nums, vector<vector<int>> &globalArr, vector<int> currArr)
{
    if (currArr.size() == nums.size())
        globalArr.push_back(currArr);
    else
    {
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = find(currArr.begin(), currArr.end(), nums[i]);
            if (it != currArr.end())
                continue;
            currArr.push_back(nums[i]);
            helper(nums, globalArr, currArr);
            currArr.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> globalArr;
    vector<int> currArr;
    helper(nums, globalArr, currArr);
    return globalArr;
}