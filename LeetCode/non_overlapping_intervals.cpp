#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> intervals)
{
    if (intervals.size() < 2)
        return 0;
    int ans = 0;
    sort(intervals.begin(), intervals.end());
    int prevEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (prevEnd > intervals[i][0])
        {
            ans++;
            prevEnd = min(prevEnd, intervals[i][1]);
        }
        else
        {
            prevEnd = intervals[i][1];
        }
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
    cout << eraseOverlapIntervals(intervals);
}