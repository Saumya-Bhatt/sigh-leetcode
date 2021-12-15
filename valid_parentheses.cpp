#include <iostream>
#include <stack>
using namespace std;
bool isComplimentary(char a, char b)
{
    int diff = (int)a - (int)b;
    if (diff == -2 || diff == -1)
    {
        return true;
    }
    return false;
}
bool isValid(string s)
{
    if (s.length() % 2 != 0)
    {
        return false;
    }
    stack<char> store;
    for (char i : s)
    {
        if (store.empty())
        {
            store.push(i);
            continue;
        }
        if (isComplimentary(store.top(), i))
        {
            store.pop();
            continue;
        }
        else
        {
            store.push(i);
        }
    }
    return store.empty();
}
int main()
{
    string s;
    cin >> s;
    cout << isValid(s);
    return 0;
}