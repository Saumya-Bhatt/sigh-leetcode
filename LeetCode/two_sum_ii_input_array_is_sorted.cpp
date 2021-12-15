#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans;
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            ans.push_back(left + 1);
            ans.push_back(right + 1);
            return ans;
        }
        if (sum < target)
            left++;
        if (sum > target)
            right--;
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}
int main()
{
    int size, target;
    vector<int> numbers;
    cin >> size >> target;
    while (size)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
        size--;
    }
    vector<int> ans = twoSum(numbers, target);
    for (int i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}