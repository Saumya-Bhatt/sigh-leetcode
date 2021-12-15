#include <iostream>
#include <vector>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
    int maxZeros = 0;
    int zCount = 0;
    int start = 0;
    for (int end = 0; end < nums.size(); end++)
    {
        if (nums[end] == 0)
            zCount++;
        while (zCount > k)
        {
            if (nums[start] == 0)
            {
                zCount--;
            }
            start++;
        }
        maxZeros = max(maxZeros, end - start + 1);
    }
    return maxZeros;
}
int main()
{
    int size, k;
    cin >> size;
    vector<int> nums;
    while (size)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
        size--;
    }
    cin >> k;
    cout << longestOnes(nums, k);
    return 0;
}