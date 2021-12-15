#include <vector>
using namespace std;
int firstOccurance(vector<int> &nums, int target)
{
    int res = -1;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
int lastOccurance(vector<int> &nums, int target)
{
    int res = -1;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            low = mid + 1;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    ans.push_back(firstOccurance(nums, target));
    ans.push_back(lastOccurance(nums, target));
    return ans;
}