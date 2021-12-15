#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int min_till_now = 100000;
    int best_profit = 0;
    for (auto i : prices)
    {
        if (i < min_till_now)
        {
            min_till_now = i;
        }
        else if (best_profit < i - min_till_now)
        {
            best_profit = i - min_till_now;
        }
    }
    return best_profit;
}
int main()
{
    int size;
    vector<int> stocks;
    cin >> size;
    while (size)
    {
        int temp;
        cin >> temp;
        stocks.push_back(temp);
        size--;
    }
    cout << maxProfit(stocks);
    return 0;
}