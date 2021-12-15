#include <stdio.h>
#include <iostream>
#include "../primaries.hpp"

using namespace std;


void selection_sort(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = A[i];
        int j = i-1;
        while (j>=0 && A[j] > temp)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;        
    }
    
}


int main()
{

    int size;
    cin >> size;
    int A[size];
    
    getInput(A, size);
    selection_sort(A, size);
    printArray(A, size);

    return 0;
}