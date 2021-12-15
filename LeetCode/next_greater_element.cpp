#include <iostream>
#include <vector>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        int match = -1;
        for (int j = 0; j < nums2.size() - 1; j++)
        {
            if (nums1[i] == nums2[j])
            {
                int iter = j;
                for (int iter = j + 1; iter < nums2.size(); iter++)
                {
                    if (nums2[j] < nums2[iter])
                    {
                        match = nums2[iter];
                        continue;
                    }
                }
            }
        }
        ans.push_back(match);
    }
    return ans;
}
int main()
{
    int size_1, size_2;
    vector<int> nums1, nums2;
    while (size_1)
    {
        int temp;
        cin >> temp;
        nums1.push_back(temp);
        size_1--;
    }
    while (size_2)
    {
        int temp;
        cin >> temp;
        nums2.push_back(temp);
        size_2--;
    }
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}