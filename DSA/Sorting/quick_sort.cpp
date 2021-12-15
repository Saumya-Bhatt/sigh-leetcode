#include <stdio.h>
#include <iostream>
#include <vector>
#include "../primaries.hpp"

using namespace std;

int partition(vector<int> &a, int low, int high)
{
    int pivot = high;
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (a[j] < a[pivot])
        {
            swap(&a[j], &a[i]);
            i++;
        }
    }
    swap(&a[i], &a[pivot]);
    return i;
}

void QuickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

int main()
{

    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    QuickSort(A, 0, N - 1);
    for (int i : A)
    {
        cout << i << " ";
    }

    return 0;
}