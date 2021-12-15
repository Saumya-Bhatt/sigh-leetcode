#include <stdio.h>
#include <vector>
#include <iostream>
#include "../primaries.hpp"

using namespace std;

int partition(vector<int> &a, int low, int high, int pivot)
{
    int pi = pivot;
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (a[j] < a[pi])
        {
            swap(&a[j], &a[i]);
            i++;
        }
    }
    swap(&a[i], &a[pi]);
    return i;
}

int main()
{

    vector<int> tmp = {8, 39, 13, 44, 35};
    int low = 0;
    int high = tmp.size() - 1;
    int pivot = 3 % (high - low + 1);
    int A = partition(tmp, low, high, pivot);

    cout << A << ":" << tmp[A];
    cout << endl;

    return 0;
}