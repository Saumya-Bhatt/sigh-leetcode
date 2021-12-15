#include <vector>
#include <algorithm>
using namespace std;
bool possible(vector<int> &piles, int h, int k)
{
    int time = 0;
    for (int p : piles)
    {
        // math.ceil(pile / speed) for pile in piles
        time += (p - 1) / k + 1;
    }
    return time <= h;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    sort(piles.begin(), piles.end());
    int low = 1;
    int high = piles[piles.size() - 1];
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (possible(piles, h, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}