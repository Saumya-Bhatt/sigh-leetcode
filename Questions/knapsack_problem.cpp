#include <vector>
using namespace std;

// RECURSIVE APPROACH

// int dp[1001][1001]; //dp[n][w]

// int knapSack(int W, int wt[], int val[], int n)
// {
//     if(dp[n][W]) return dp[n][W];
//     int result;
//     if(W==0 || n==0) result = 0;
//     else if(wt[n-1] > W) result = knapSack(W, wt, val, n-1);
//     else {
//       int notUsingWeight = knapSack(W, wt, val, n-1);
//       int usingWeight = val[n-1] + knapSack(W-wt[n-1], wt, val, n-1);
//       result = max(notUsingWeight, usingWeight);
//     }
//     dp[n][W] = result;
//     return result;
// }

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0; // base case
            else if (wt[i - 1] <= w)
                // usingWieght + notUsingWeight
                K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                // wt[i-1] has exceeded the capacity, so continuing
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}