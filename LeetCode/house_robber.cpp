#include <vector>
#include <algorithm>
using namespace std;
int asked[101] = {false};
int memory[101];

int ans(vector<int> &nums, int idx)
{
    int answer = 0;

    /* if we have already asked the computer to calculate answer(x), we won't ask it again!
        We will simply return the calculated answer from our memory.*/
    if (asked[idx] == true)
        return memory[idx];

    /* We are now asking computer something, obviously we have ensured that we aren't
        asking computer something we have already asked. */
    asked[idx] = true;

    if (idx == 0)
        answer = nums[0];

    else if (idx == 1)
        answer = max(nums[1], nums[0]);

    else
        answer = max(ans(nums, idx - 1), nums[idx] + ans(nums, idx - 2));

    /*Computer just found out what we asked it to calculate, we shall not forget it.
        To not forget it, we will store it in our memory*/
    memory[idx] = answer;

    return answer;
}

int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    return ans(nums, nums.size() - 1);
}