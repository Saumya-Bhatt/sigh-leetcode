#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.size() == 1)
        return 1;
    int numArrows = 0;
    int max = INT_MIN;
    sort(points.begin(), points.end());
    for (auto &p : points)
    {
        if (max < p[0])
        {
            numArrows++;
            max = p[1];
        }
        else
        {
            max = min(max, p[1]);
        }
    }
    return numArrows;
}
int main()
{
    int size;
    vector<vector<int>> points;
    cin >> size;
    while (size)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;
        points.push_back(vector<int>{tempA, tempB});
        size--;
    }
    cout << findMinArrowShots(points);

    return 0;
}