#include <iostream>
using namespace std;
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    int counts[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
    }
    for (auto i : counts)
    {
        if (i)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << isAnagram(s, t);
    return 0;
}