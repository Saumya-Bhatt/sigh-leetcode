#include <iostream>
#include <cstring>
using namespace std;
int memory[59];
int maximum(int a, int b, int c)
{
    return max(max(a, b), c);
}
int helper(int n)
{
    if (memory[n] != -1)
        return memory[n];
    int max_i = 0;
    for (int i = 1; i < n; i++)
    {
        max_i = maximum(max_i, i * (n - i), i * helper(n - i));
    }
    memory[n] = max_i;
    return memory[n];
}
int integerBreak(int n)
{
    memset(memory, -1, sizeof(memory));
    memory[0] = 0;
    memory[1] = 0;
    memory[2] = 1;
    memory[3] = 2;
    return helper(n);
}