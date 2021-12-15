#include <iostream>
#include <stdio.h>
#include "../primaries.hpp"

using namespace std;

void merge(int arr[], int lb, int m, int ub)
{
    int n1 = m - lb + 1;
    int n2 = ub - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays lb[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[lb + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[lb..ub]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = lb;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elbements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int lb, int ub)
{
    if (ub > lb)
    {
        int mid = (lb + ub)/2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid+1, ub);
        merge(A, lb, mid, ub); 
    } 
}

int main()
{
    int size;
    cin >> size;
    int A[size];

    getInput(A, size);
    mergeSort(A, 0, size-1);
    printArray(A, size);

    return 0;
}