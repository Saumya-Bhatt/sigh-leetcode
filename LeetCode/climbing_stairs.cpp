#include <iostream>
#include <vector>
using namespace std;
int memory[46];
bool asked[46] = {false};
int climbStairs(int n)
{
    int ans;
    if (asked[n] == true)
    {
        return memory[n];
    }
    asked[n] = true;
    if (n == 1)
        ans = 1;
    else if (n == 2)
        ans = 2;
    else
        ans = climbStairs(n - 1) + climbStairs(n - 2);
    memory[n] = ans;
    return ans;
}