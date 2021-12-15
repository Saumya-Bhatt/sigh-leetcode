#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <bits/stdc++.h>

// set - each operation does in log(n) time;
// inserting into vector will not automatically sort it unlike set.

using namespace std;


int main()
{
    
    set<int> S = {77,88,99};

    // insert number in set 
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    // Will internally store values in ascending order
    for(int x:S)
    {
        cout << x << " ";
    }
    cout << endl;
    // -10, -1, 1, 2

    // finding if value exists in set
    auto it = S.find(-1);
    if(it == S.end())
    {
        cout << "not present\n";
    } else {
        cout << "Present\n";
        cout << *it << endl;
    }

    // finding first number in set which is greater than 0
    auto it2 = S.lower_bound(0); 
    auto it3 = S.upper_bound(0);
    cout << *it2 << " " << *it3 << endl;

    // will point to end if does not find anything
    auto it4 = S.upper_bound(100);
    if (it4 == S.end())
    {
        cout << "Can't find something like that";
    }
    cout << endl;

    // erase number
    S.erase(-10);
    for(int x:S)
    {
        cout << x << " ";
    }

    return 0;
}