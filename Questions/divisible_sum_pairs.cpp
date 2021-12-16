#include <iostream>
#include <vector>
using namespace std;
int divisibleSumPairs(int n, int k, vector<int> &arr)
{
    int rem[k];
    for (int i = 0; i < k; i++)
    {
        rem[i] = 0;
    }
    for (int i : arr)
    {
        rem[i % k]++;
    }
    int sum = 0;

    // pairs where each are divisible by k
    // (num in that bracket)C2
    sum += (rem[0] * (rem[0] - 1)) / 2;

    // if even k, means can take any 2 from it's middle elements also
    if (k % 2 == 0)
    {
        sum += (rem[k / 2] * (rem[k / 2] - 1)) / 2;
    }

    for (int i = 1; i <= k / 2 && i != k - i; i++)
    {
        sum += rem[i] * rem[k - i];
    }

    return sum;
}
int main()
{
    int n, k;
    vector<int> arr;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << divisibleSumPairs(n, k, arr);
}