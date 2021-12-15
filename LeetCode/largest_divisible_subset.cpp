#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    // sorting so only have to do nums[j]%nums[i] and not converse
    sort(nums.begin(), nums.end());

    // count[i] = length of longest subarray ending with nums[i]
    vector<int> count(nums.size(), 0);

    // parent[i] = stores index of the largestelement j such that nums[j] % nums[i] == 0 and j > i
    // used to link what previous element to be added to the subset
    vector<int> parent(nums.size(), 0);

    int max = 0;       // stores max length of the subarray
    int max_index = 0; // stores index of max

    // end -> start
    // so that the largest element in answer can come last
    for (int i = nums.size() - 1; i >= 0; --i) //
    {

        for (int j = i; j < nums.size(); ++j)
        {

            if (nums[j] % nums[i] == 0 && count[i] < 1 + count[j])
            {
                // if a[j] mod a[i] == 0, it means count[j] can form a larger subset by putting nums[i] into count[j]
                count[i] = 1 + count[j];
                parent[i] = j;

                if (count[i] > max)
                {
                    max = count[i];
                    max_index = i;
                }
            }
        }
    }

    vector<int> ret;
    for (int i = 0; i < max; ++i)
    {
        ret.push_back(nums[max_index]);
        max_index = parent[max_index];
    }

    return ret;
}