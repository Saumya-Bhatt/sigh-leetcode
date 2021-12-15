#include <iostream>
using namespace std;
int memory[1001];
int helper(int n)
{
    if (memory[n] != -1)
        return memory[n];
    int max_i = 0;
    for (int i = 0; i < n; i++)
    {
        max_i = max(max_i, (i * (n - i)), i * helper(n - i));
    }
    memory[n] = max_i;
    return memory[n];
}
int maximumProductCutting(int n)
{
    memory[0] = 0;
    memory[1] = 0;
    memory[2] = 1;
    return helper(n);
}