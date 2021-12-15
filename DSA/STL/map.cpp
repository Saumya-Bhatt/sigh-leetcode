#include <iostream>
#include <stdio.h>
#include <map>
#include <bits/stdc++.h>

// takes log(n) time

using namespace std;

int main()
{
    // initializing map
    map<int, int> A;

    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[1000324] = 42;

    map<char, int> cnt;

    // storing integer frequency
    string x = "Saumya Bhatt";
    for(char c:x)
    {
        cnt[c]++;  // log(n)
    }
    cout << cnt['a'] << " " << cnt['t'] << endl;

    // finding element
    auto it = cnt.find('a');
    cout << it->first << " " << it->second << endl;

    return 0;
}