#include <iostream>
using namespace std;
int countVowelStrings(int n)
{
    int ans[n + 1][5];

    /* We trivially know the answer for the case when n = 1 this is the base case
        of our problem.*/
    for (int i = 0; i < 5; ++i)
        ans[1][i] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            ans[i][j] = 0;
            for (int k = 0; k <= j; ++k)
                ans[i][j] += ans[i - 1][k];
        }
    }

    int sum = 0;

    for (int i = 0; i < 5; ++i)
        sum += ans[n][i];

    return sum;
}