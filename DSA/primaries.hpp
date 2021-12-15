#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

void printArray(int A[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << A[i] << " ";
    }
    printf("\n");
}

void getInput(int A[], int size)
{
    int temp;
    int count = 0; 

    do
    {
        cin >> temp;
        A[count] = temp;
        count++;
    } while (count < size);
    
    
}

void swap(int *ft, int *lt)
{
    int temp = *ft;
    *ft = *lt;
    *lt = temp;
}