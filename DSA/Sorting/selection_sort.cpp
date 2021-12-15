#include <stdio.h>
#include <iostream>
#include "../primaries.hpp"

using namespace std;

void selectionSort(int A[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&A[i], &A[min]);
        }  
    }
    
}

int main()
{

    int size;
    cin >> size;
    int A[size];
    
    getInput(A, size);
    selectionSort(A, size);
    printArray(A, size);   

    return 0;
}