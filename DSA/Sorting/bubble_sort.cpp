#include <stdio.h>
#include <iostream>

#include "../primaries.hpp"

using namespace std;

void bubbleSort(int A[], int size)
{
    int i,j;
    bool swapped;

    for(i=0; i<size-1; i++)
    {
        swapped = false;
        for(j=0; j<size-1-i; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                swapped = true;
            } 
        }
        if (swapped == false)
        {
            break;
        }
        
    }
}


int main()
{
    int size;
    cin >> size;
    int A[size];
    
    getInput(A, size);
    bubbleSort(A, size);
    printArray(A, size);

    return 0;
}
