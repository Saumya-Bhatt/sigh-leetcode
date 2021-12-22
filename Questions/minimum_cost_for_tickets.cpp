#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;

// index : calculating cost starting from that day
int helper(vector<int> &day, vector<int> &cost, int si)
{
    int n = day.size();
    if (si >= n)
        return 0;
    if (dp[si])
        return dp[si];

    int cost_day = cost[0] + helper(day, cost, si + 1); // pass valid for 1 day, so skipping to the next day from index

    int i;
    for (i = si; i < n and day[i] < day[si] + 7; i++)
        ; // pass valid for 7 days, so skipping to the next week from index
    int cost_week = cost[1] + helper(day, cost, i);

    for (i = si; i < n and day[i] < day[si] + 30; i++)
        ; // pass valid for 30 days, so skipping to the next month from index
    int cost_month = cost[2] + helper(day, cost, i);

    dp[si] = min({cost_day, cost_week, cost_month});
    return dp[si];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    dp.resize(367);
    return helper(days, costs, 0);
}