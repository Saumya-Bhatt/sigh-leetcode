#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    int len = intervals.size();

    // will map the start of each interval to their index in the array intervals
    map<int, int> start_pos_index;

    vector<int> ans;

    // remember to do this before doing any lower bounds. Will sort the map according to the key which here is the start
    sort(intervals[0].begin(), intervals[0].end());

    for (int i = 0; i < len; i++)
    {
        start_pos_index[intervals[i][0]] = i; // (start,index)
    }
    for (auto in : intervals)
    {
        int end = in[1]; // get current end of the interval

        // find the required interval, whose start is just >= to our current end
        auto itr = start_pos_index.lower_bound(end);

        // if didn't find the required lower bound (will point to the next greatest one which here would be the last), add -1
        if (itr == start_pos_index.end())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(itr->second);
        }
    }
    return ans;
}