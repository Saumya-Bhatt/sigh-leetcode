#include <vector>
#include <math.h>
using namespace std;

int helper(int arr[], int &n, vector<vector<int>> &dp, int &total, int delta, int index)
{
    if (dp[index][delta] != -1)
        return dp[index][delta];
    if (index == n)
        return abs((total - delta) - delta);
    int considered = helper(arr, n, dp, total, delta + arr[index], index + 1);
    int notConsidered = helper(arr, n, dp, total, delta, index + 1);
    return dp[index][delta] = min(considered, notConsidered);
}

int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return helper(arr, n, dp, sum, 0, 0);
}