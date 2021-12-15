#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// decreasing order
bool f(int x, int y)
{
    return x > y;
}

int main()
{

    // initializing vector
    vector<int> A = {11, 2, 3, 14};

    // accessing element
    cout << A[1] << endl;

    // sort - O(nlogn)
    sort(A.begin(), A.end());

    // binary search - O(logn)
    bool present = binary_search(A.begin(), A.end(), 3);
    
    // insert elements
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    // 2,3,11,14,100,100,100,100, 123

    // can only do this on sorted vector
    // finding first occurence of 100
    auto it = lower_bound(A.begin(), A.end(), 100); // >=100  | auto === vector<int>::iterator
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // >100
    
    cout << *it << " " << *it2 << endl;  // iterators are pointers
    cout << it-it2 << endl; // O(1)
    // it=100 (first) | it2 = 123 | 4 (this is the count of 100)

    // sorting in reverse order - takes in comparator function
    sort(A.begin(), A.end(), f);

    // printing vector
    for(int x:A)
    {
        cout << x << " ";
    }
    cout << endl;

    // iterate and perform functions on elements
    for (int &i:A)  // iterate by reference
    {
        i++;
        cout << i << " ";
    }
    cout << endl;
    
    

    return 0;
}