#include <iostream>
using namespace std;
#define MOD 1000000007
int dp[31][1001];
int helper(int d, int t, int f)
{
    if (d == 0 && t == 0)
        return 1;
    else if (d <= 0 || t <= 0 || d * f < t || d > t)
        return 0;
    else if (dp[d][t])
        return dp[d][t];
    for (int i = 1; i <= f; i++)
        dp[d][t] = (dp[d][t] + helper(d - 1, t - i, f)) % MOD;
    return dp[d][t] % MOD;
}
int numRollsToTarget(int d, int f, int target)
{
    return helper(d, target, f);
}
