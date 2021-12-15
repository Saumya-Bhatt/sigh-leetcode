#include <vector>
#include <algorithm>
using namespace std;
int shipWithinDays(vector<int> &weights, int days)
{
    int left = 0, right = 0, mid;
    for (int w : weights)
    {
        left = max(left, w);
        right += w;
    }
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int days_needed = 1, curr_weight = 0;

        // function to check whether it is possible to ship within 'days' days if the ship's capacity is 'mid'
        for (int i = 0; i < weights.size() && days_needed <= days; curr_weight += weights[i++])
        {
            if (curr_weight + weights[i] > mid)
            {
                curr_weight = 0;
                days_needed++;
            }
        }

        // if not possible, we need to increase capacity
        if (days_needed > days)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1; // else decrease it
        }
    }
    return mid;
}