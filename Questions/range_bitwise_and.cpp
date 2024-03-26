class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans;
        while (left < right)
        {
            right = right & (right - 1);
        }
        return right;
    }
};