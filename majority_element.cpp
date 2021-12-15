#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int maj_index = 0;
    int count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[maj_index])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return nums[maj_index];
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
    cout << majorityElement(nums);
}
