#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty() || intervals.size() == 1)
        return intervals;
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (ans.back()[1] < intervals[i][0])
            ans.push_back(intervals[i]);
        else
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
    return ans;
}
int main()
{
    int size;
    vector<vector<int>> intervals;
    cin >> size;
    while (size)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;
        intervals.push_back(vector<int>{tempA, tempB});
        size--;
    }
    vector<vector<int>> ans = merge(intervals);
    for (auto inter : ans)
    {
        cout << inter[0] << " " << inter[1] << endl;
    }
}