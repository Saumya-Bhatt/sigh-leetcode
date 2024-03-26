class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int actual_sum = n * (n + 1) / 2;
        int real_sum = 0;
        for (auto i : nums)
            real_sum += i;
        return actual_sum - real_sum;
    }
};