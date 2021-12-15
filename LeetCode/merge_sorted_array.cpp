#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int tar = n + m - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[tar--] = nums1[i--];
        else
            nums1[tar--] = nums2[j--];
    }
}
int main()
{
    int size1, size2, m, n;
    cin >> size1 >> size2 >> m >> n;
    vector<int> nums1, nums2;
    while (size1)
    {
        int temp;
        cin >> temp;
        nums1.push_back(temp);
        size1--;
    }
    while (size2)
    {
        int temp;
        cin >> temp;
        nums2.push_back(temp);
        size2--;
    }
    merge(nums1, m, nums2, n);
    for (int i : nums1)
    {
        cout << i << ' ';
    }
    return 0;
}