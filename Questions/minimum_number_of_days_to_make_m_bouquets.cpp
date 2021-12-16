#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int minDays(vector<int> &bloomDay, int m, int k)
{
    if (m * k > bloomDay.size())
        return -1;
    int left = 1, right = 1e9, mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        int bouquets = 0, flowers = 0;
        for (int item : bloomDay)
        {
            if (item > mid)
            {
                // if not in bloom, change flower status to 0
                // flowers/k will check that all the flowers before this one, are ==k and only then add it to our bouqet count
                flowers = 0;
            }
            else if (++flowers >= k)
            {
                bouquets += flowers / k;
                flowers = 0;
            }
        }
        if (bouquets < m)
            left = mid + 1;
        else
            right = mid;
    }
    // are returning left as we want the lower bound and not the exact value
    return left;
}