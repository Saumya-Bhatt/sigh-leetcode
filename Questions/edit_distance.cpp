#include <vector>
#include <string>
using namespace std;

// f(i,j) = min( [f(i,j-1) + Ca] , [f(i-1,j) + Cd] , [f(i-1,j-1) + Cr] )

// f(i,j) = cost to make string1[0:i] and string2[0:j] equal
// Ca, Cd, Cr = Cost of adding/deleting/replacing

// f(i,j-1) => adding to string1 == deleting from string2
// f(i-1,j) => deleting from string1
// f(i-1,j-1) => replacing in string1 == considering both are equal, move on

int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{

    if (i == 0)
        return j; // add all the remaining chars from string2
    if (j == 0)
        return i; // delete all chars remaining from string1

    if (dp[i][j] != -1)
        return dp[i][j]; // memoization

    // doing i-1,j-1 since we initiated i,j as m,n
    if (word1[i - 1] == word2[j - 1])
        return dp[i][j] = helper(word1, word2, i - 1, j - 1, dp); // matched! move down the char array together

    int addition = helper(word1, word2, i, j - 1, dp) + 1;
    int deletion = helper(word1, word2, i - 1, j, dp) + 1;
    int replace = helper(word1, word2, i - 1, j - 1, dp) + 1;
    return dp[i][j] = min(addition, min(deletion, replace));
}

int minDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    if (m < n)
        return minDistance(word2, word1);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return helper(word1, word2, m, n, dp);
}