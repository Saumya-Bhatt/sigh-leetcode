#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int max = 0;
    while (left < right)
    {
        int area = (height[left] < height[right] ? height[left] : height[right]) * (right - left);
        max = area > max ? area : max;
        height[left] <= height[right] ? left++ : right--;
    }
    return max;
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
    cout << maxArea(height);
    return 0;
}