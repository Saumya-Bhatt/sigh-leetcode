#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    if (intervals.size() == 0)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    vector<vector<int>> ans;
    int index = 0;
    while (index < intervals.size() && intervals[index][1] < newInterval[0])
    {
        ans.push_back(intervals[index++]);
    }
    while (index < intervals.size() && intervals[index][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[index][0]);
        newInterval[1] = max(newInterval[1], intervals[index][1]);
        index++;
    }
    ans.push_back(newInterval);
    while (index < intervals.size())
    {
        ans.push_back(intervals[index++]);
    }
    return ans;
};
int main()
{
    int size_1, size_2;
    vector<vector<int>> intervals;
    vector<int> newInterval;
    cin >> size_1;
    while (size_1)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;
        intervals.push_back(vector<int>{tempA, tempB});
        size_1--;
    }
    size_2 = 2;
    while (size_2)
    {
        int temp;
        cin >> temp;
        newInterval.push_back(temp);
        size_2--;
    }
    vector<vector<int>> ans = insert(intervals, newInterval);
    for (auto i : ans)
    {
        cout << i[0] << ' ' << i[1] << endl;
    }
    return 0;
}