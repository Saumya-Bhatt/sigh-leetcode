#include <vector>
#include <string>
using namespace std;

// ptr_1 sees from which character of text1 do we have to break it. Same for ptr_2
int helper(string &text1, string &text2, int ptr_1, int ptr_2, vector<vector<int>> &dp)
{

    // if can no longer divide the text based on the pointers, there can be no matching character
    if (ptr_1 >= text1.size() || ptr_2 >= text2.size())
        return 0;

    if (dp[ptr_1][ptr_2] != -1)
        return dp[ptr_1][ptr_2];

    if (text1[ptr_1] == text2[ptr_2])
    {

        // if we got a matching, we return 1 as the answer and proceed forward down the tree by clipping both text1 and text2
        return 1 + helper(text1, text2, ptr_1 + 1, ptr_2 + 1, dp);
    }

    // we're taking the max since we don't want all possible matches, but only those that can give us the longest substring
    return dp[ptr_1][ptr_2] = max(helper(text1, text2, ptr_1 + 1, ptr_2, dp), helper(text1, text2, ptr_1, ptr_2 + 1, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    return helper(text1, text2, 0, 0, dp);
}

//     int longestCommonSubsequence(string &text1, string &text2) {
//         int m = text1.size();
//         int n = text2.size();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
//                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[m][n];
//     }