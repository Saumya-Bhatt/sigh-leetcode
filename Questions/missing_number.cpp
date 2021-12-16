#include <iostream>
#include <vector>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] - i;
    }
    return nums.size() - sum;
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
    cout << missingNumber(nums);
}