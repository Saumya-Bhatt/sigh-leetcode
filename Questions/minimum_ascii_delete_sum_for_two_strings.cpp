#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int remainingSum(string &s, int i)
{
    int sum = 0;
    for (int j = i; j < s.size(); j++)
    {
        sum += s[j];
    }
    return sum;
}

int helper(string &s1, string &s2, int &m, int &n, vector<vector<int>> &dp, int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    int sum = 0;
    if (i == m || j == n)
    {
        if (i == m && j == n)
            sum = 0;
        else
            sum = (i == m) ? remainingSum(s2, j) : remainingSum(s1, i);
    }
    else if (s1[i] == s2[j])
        sum = helper(s1, s2, m, n, dp, i + 1, j + 1);
    else
        sum = min(helper(s1, s2, m, n, dp, i + 1, j) + s1[i], helper(s1, s2, m, n, dp, i, j + 1) + s2[j]);
    dp[i][j] = sum;
    return sum;
}

int minimumDeleteSum(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return helper(s1, s2, m, n, dp, 0, 0);
}

// sea:eat
//   |   |     (2)

// sea:eat             sea:eat
//  |  |   (1+1)         |  |  (1+2)

// sea:eat             sea:eat
// |   _   (1)          |  |    (1+1)
//                     sea:eat
//                     |   _    (1)