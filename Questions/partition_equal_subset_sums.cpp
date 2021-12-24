#include <vector>
using namespace std;

bool isPossible(vector<int> &nums, vector<vector<bool>> &dp, vector<vector<bool>> &visited, int sum, int index)
{
    // base cases
    if (index < 0 || sum < 0)
        return false;
    if (sum == 0)
        return dp[sum][index] = true; // found the target sum in the array

    if (visited[sum][index])
        return dp[sum][index];
    visited[sum][index] = true;

    bool considerNum = isPossible(nums, dp, visited, sum - nums[index], index - 1);
    bool notConsiderNum = isPossible(nums, dp, visited, sum, index - 1);

    return dp[sum][index] = considerNum || notConsiderNum;
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    for (int i : nums)
        sum += i;

    if (sum % 2 != 0)
        return false; // if sum is odd

    // Find if there is subset with sum/2 present in the given array 'nums'
    //  only need to see if we can find a subset for sum/2 as the remaining would automatically be equal since the total is sum.
    sum = sum / 2;
    vector<vector<bool>> dp(sum + 1, vector<bool>(n, false));
    vector<vector<bool>> visited(sum + 1, vector<bool>(n, false));
    return isPossible(nums, dp, visited, sum, n - 1);
}