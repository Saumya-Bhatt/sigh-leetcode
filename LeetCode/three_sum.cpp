#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int left_ptr = i + 1;
        int right_ptr = nums.size() - 1;
        while (left_ptr < right_ptr)
        {
            int sum = nums[i] + nums[left_ptr] + nums[right_ptr];
            if (sum > 0)
            {
                right_ptr--;
            }
            else if (sum < 0)
            {
                left_ptr++;
            }
            else
            {
                ans.push_back(vector<int>{nums[i], nums[left_ptr], nums[right_ptr]});
                while (left_ptr < right_ptr && nums[left_ptr] == nums[left_ptr + 1])
                {
                    left_ptr++;
                }
                while (left_ptr < right_ptr && nums[right_ptr] == nums[right_ptr - 1])
                {
                    right_ptr--;
                }
                left_ptr++;
                right_ptr--;
            }
        }
    }
    return ans;
}
int main()
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
    vector<vector<int>> ans = threeSum(nums);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}