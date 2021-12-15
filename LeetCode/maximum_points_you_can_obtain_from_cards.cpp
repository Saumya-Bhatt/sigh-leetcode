#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
    int max_sum = 0;
    int n = cardPoints.size();
    for (int i = n - k; i < n; i++)
    {
        max_sum += cardPoints[i];
    }
    int window_sum = max_sum;
    int end_point = 0;
    for (int i = n - k; i < n; i++)
    {
        window_sum -= cardPoints[i];
        window_sum += cardPoints[end_point++];
        if (window_sum >= max_sum)
            max_sum = window_sum;
    }
    return max_sum;
}
int main()
{
    int size, k;
    cin >> size >> k;
    vector<int> cardPoints;
    while (size)
    {
        int temp;
        cin >> temp;
        cardPoints.push_back(temp);
        size--;
    }
    cout << endl;
    cout << maxScore(cardPoints, k);
}