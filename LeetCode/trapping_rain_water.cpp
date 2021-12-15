#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    if (n < 3)
    {
        return 0;
    }
    int left[n];
    int right[n];
    int left_max = -1;
    int right_max = -1;
    int water = 0;

    left[0] = 0;
    right[n - 1] = 0;

    for (int i = 1; i < n; i++)
    {
        if (height[i - 1] > left_max)
        {
            left_max = height[i - 1];
        }
        if (height[n - i] > right_max)
        {
            right_max = height[n - i];
        }
        left[i] = left_max;
        right[n - 1 - i] = right_max;
    }
    for (int i = 0; i < n; i++)
    {
        int diff = (left[i] > right[i] ? right[i] : left[i]) - height[i];
        if (diff <= 0)
        {
            continue;
        }
        water += diff;
    }
    return water;
}
int main()
{
    int size;
    vector<int> height;
    cin >> size;
    while (size)
    {
        int temp;
        cin >> temp;
        height.push_back(temp);
        size--;
    }
    cout << trap(height);
    return 0;
}