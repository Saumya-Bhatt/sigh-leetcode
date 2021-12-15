#include <iostream>
using namespace std;
int memory[101][101];
bool asked[101][101] = {false};
int uniquePaths(int m, int n)
{
    if (n == 1 && m == 1)
        return 1;
    if (n == 0 || m == 0)
        return 0;
    if (asked[m][n])
        return memory[m][n];
    asked[m][n] = true;
    int ans = uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
    memory[m][n] = ans;
    return ans;
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n);
    return 0;
}