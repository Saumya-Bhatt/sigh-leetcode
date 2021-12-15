#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool containsDuplicate(vector<int> nums)
{
    map<int, int> hash_num;
    for (auto i : nums)
    {
        hash_num[i]++;
    }
    return hash_num.size() != nums.size();
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
    cout << containsDuplicate(nums);
    return 0;
}