#include <iostream>
#include <vector>
using namespace std;
int change(int amount, vector<int> &coins)
{
    vector<vector<int>> dp_table(coins.size() + 1, vector<int>(amount + 1));
    dp_table[0][0] = 1;
    for (int i = 1; i <= coins.size(); i++)
    {
        dp_table[i][0] = 1;
        for (int j = 1; j <= amount; j++)
        {
            //doing i-1 as we are initializing i from 1
            int coin = coins[i - 1];
            int coinNotUsed = dp_table[i - 1][j];
            int coinUsed = (j - coin >= 0 ? dp_table[i][j - coin] : 0);
            dp_table[i][j] = coinUsed + coinNotUsed;
        }
    }
    return dp_table[coins.size()][amount];
}
int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << change(amount, coins);
    return 0;
}