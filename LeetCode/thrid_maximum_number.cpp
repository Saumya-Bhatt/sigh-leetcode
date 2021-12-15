#include <iostream>
#include <vector>
#include <set>
using namespace std;
int thirdMax(vector<int> &nums)
{
    long long a, b, c;
    a = b = c = LLONG_MIN;
    for (auto i : nums)
    {
        if (i <= c || i == b || i == a)
            continue;
        c = i;
        if (c > b)
            swap(b, c);
        if (b > a)
            swap(a, b);
    }
    return c == LLONG_MIN ? a : c;
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
    }
    cout << thirdMax(nums);
}