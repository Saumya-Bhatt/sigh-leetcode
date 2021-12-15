#include <stdio.h>
#include <iostream>
#include "primaries.hpp"

using namespace std;

void linearSearch(int A[], int size, int num)
{
    bool flag = false;
    int index;
    for (int i = 0; i < size; i++)
    {
        if (A[i] == num)
        {
            flag = true;
            index = i;
        }
    }
    if (flag == true)
    {
        cout << "Number " << num << " found at index : " << index;
    } else {
        cout << "No such number found";
    }  
}

int main() 
{
    int size;
    cin >> size;
    int A[size];

    getInput(A, size);

    int num;
    cin >> num;
    linearSearch(A, size, num);

    return 0;
}