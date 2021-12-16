#include <iostream>
#include <vector>
using namespace std;
void helper(vector<int> &nums, vector<vector<int>> &globalArray, vector<int> currArray, int index)
{
    if (index == nums.size())
    {
        globalArray.push_back(currArray);
        return;
    }
    else
    {
        helper(nums, globalArray, currArray, index + 1);
        currArray.push_back(nums[index]);
        helper(nums, globalArray, currArray, index + 1);
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> currArray = {};
    vector<vector<int>> globalArray = {};
    int index = 0;
    helper(nums, globalArray, currArray, index);
    return globalArray;
}