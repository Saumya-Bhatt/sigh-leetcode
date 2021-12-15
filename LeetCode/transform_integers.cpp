#include <iostream>
using namespace std;
int transformInteger(int n)
{
    int sum = 0;
    for (int a = 2; a <= n / 2; a++)
    {
        int x = 2;
        while (a * x <= n)
        {
            // cout << "a: " << a << " | b: " << a * x << " | x:" << x << endl;
            sum += x;
            x++;
        }
    }
    return sum * 4;
}
int main()
{
    int n;
    cin >> n;
    cout << transformInteger(n);
    return 0;
}