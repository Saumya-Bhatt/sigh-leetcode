#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> twoSum(vector<int> nums, int target)
{
    map<int, int> num_map;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (num_map.find(target - nums[i]) != num_map.end())
        {
            ans.push_back(num_map[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        num_map[nums[i]] = i;
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
    vector<int> ans = twoSum(nums, target);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}