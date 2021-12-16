#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<int> position, int minDist, int m)
{
    int numBall = 1;
    int lastPos = position[0];
    int size = position.size();

    for (int index = 1; index < size; index++)
    {
        if ((position[index] - lastPos) >= minDist)
        {
            numBall++;
            lastPos = position[index];
        }
        if (numBall >= m)
        {
            return true;
        }
    }
    return false;
}
int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end());
    int low = 0;
    int high = *max_element(position.begin(), position.end());

    while (low < high)
    {
        int mid = low + (high - low + 1) / 2;
        if (isPossible(position, mid, m))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    int size, m;
    vector<int> position;
    cin >> size;
    while (size)
    {
        int temp;
        cin >> temp;
        position.push_back(temp);
    }
    cin >> m;
    cout << maxDistance(position, m);
    return 0;
}