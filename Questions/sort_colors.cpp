#include <iostream>
#include <vector>
using namespace std;
void sortColors(vector<int> &nums)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    for (int i : nums)
    {
        if (i == 0)
            zero++;
        if (i == 1)
            one++;
        if (i == 2)
            two++;
    }
    int i = 0;
    while (i < nums.size())
    {
        while (zero > 0)
        {
            nums[i++] = 0;
            zero--;
        }
        while (one > 0)
        {
            nums[i++] = 1;
            one--;
        }
        while (two > 0)
        {
            nums[i++] = 2;
            two--;
        }
    }
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
    sortColors(nums);
    for (int i : nums)
    {
        cout << i << ' ';
    }
    return 0;
}