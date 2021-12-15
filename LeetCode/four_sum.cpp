#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.size() < 4)
        return ans;
    sort(nums.begin(), nums.end());
    for (unsigned int i = 0; i < nums.size() - 3; i++)
    {
        for (unsigned int j = i + 1; j < nums.size() - 2; j++)
        {
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                if (sum > target)
                {
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
            while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                j++;
        }
        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
    }
    return ans;
}
int main()
{
    int size, target;
    vector<int> nums;
    cin >> size;
    while (size)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
        size--;
    }
    cin >> target;
    vector<vector<int>> ans = fourSum(nums, target);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}