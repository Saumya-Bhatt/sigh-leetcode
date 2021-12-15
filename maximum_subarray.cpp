#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int max_num = *max_element(nums.begin(), nums.end());
    if (max_num < 0)
    {
        return max_num;
    }
    int curr_sum = 0;
    int max_sum = 0;
    for (int num : nums)
    {
        curr_sum += num;
        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_sum;
}
void main()
{
    int size;
    vector<int> nums;
    cin >> size;
    while (size)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
        size--;
    }
    cout << maxSubArray(nums);
}