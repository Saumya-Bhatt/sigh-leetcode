#include <vector>
#include <deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    // store max of the first k elements
    for (int i = 0; i < k; i++)
    {
        // if we found an elemnt which is greater than the current element in dq, drop all the remaining elment and store only that max element
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);

    // for the rest n-k elements
    for (int i = k; i < nums.size(); i++)
    {

        // empty the queue so that only elments of the current window take part
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_back();
        }

        // find max in the window and add it to the ans
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}