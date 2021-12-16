#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<string, bool> dp;
map<string, int> asked;
bool wordBreak(string s, vector<string> &wordDict)
{
    if (s.length() == 0)
        return true;
    if (asked[s] != 0)
        return dp[s];
    asked[s] = 1;
    int s_len = s.length();
    bool res = false;
    for (auto i : wordDict)
    {
        string prefix = s.substr(0, i.length());
        if (prefix == i && wordBreak(s.substr(i.length(), s_len), wordDict))
            res = true;
    }
    dp[s] = res;
    return dp[s];
}