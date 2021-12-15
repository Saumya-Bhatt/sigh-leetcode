#include <iostream>
#include <stack>
using namespace std;
string removeDuplicates(string s)
{
    string res = "";
    for (char c : s)
    {
        if (res.size() && c == res.back())
        {
            res.pop_back();
        }
        else
        {
            res.push_back(c);
        }
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << removeDuplicates(s);
    return 0;
}