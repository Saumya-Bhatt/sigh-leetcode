#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// helper function to determine whether a string is a predecessor to other or not
bool isPredecessor(string &wordA, string &wordB)
{
    if (wordA.size() + 1 != wordB.size())
        return false;
    for (int i = 0; i < wordB.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < wordB.size(); j++)
        {
            if (j == i)
                continue;
            temp.push_back(wordB[j]);
        }
        if (temp == wordA)
            return true;
    }
    return false;
}

int longestStrChain(vector<string> &words)
{

    int n = words.size();

    // to ensure strings are sorted according to their size in increasing order
    sort(words.begin(), words.end(), [](const string &a, const string &b)
         { return a.size() < b.size(); });

    int max_len = 0;
    vector<int> dp(n, 1); // dp[i] = length of largest subarray such that the last element is words[i] string.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            bool res = isPredecessor(words[j], words[i]);
            // cout<<words[j]<<' '<<words[i]<<' '<<res<<endl;
            if (res && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (max_len < dp[i])
            max_len = dp[i];
    }
    return max_len;
}