#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lengthOfLIS(vector<int> &nums)
{
    // lis[4] = 1 + max(lis[3], lis[2], lis[1])
    // 1=based-index
    // lis[i] = lis for element ending at index i
    // 1+ => are fixing that number

    // all values initated to 1, since all
    // subsequence ending with number nums[i]
    // will have a subsequence {nums[i]}, of size 1
    vector<int> lis_till_here(nums.size(), 1);

    int max_lis = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        // we want all the lis which are less than the current
        // eg. for lis[4] we need lis[1], lis[2], lis[3]
        for (int j = 0; j < i; j++)
        {

            // only change lis if nums before i (here j) are less, else lis is always smaller
            // only update lis[i] if it is advantageous (here only update if is greater)
            // lis[j] + 1 means, greatest lis till nums[j] and include nums[j] (1) as well
            if (nums[j] < nums[i] && lis_till_here[j] + 1 > lis_till_here[i])
            {
                lis_till_here[i] = lis_till_here[j] + 1;
            }
        }
        if (lis_till_here[i] > max_lis)
            max_lis = lis_till_here[i];
    }

    return max_lis;
}