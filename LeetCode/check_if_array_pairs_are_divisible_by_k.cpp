#include <iostream>
#include <vector>
using namespace std;
bool canArrange(vector<int> &arr, int k)
{
    int freq[k];
    for (int i = 0; i < k; i++)
        freq[i] = 0;
    for (int i : arr)
        freq[((i % k) + k) % k]++;
    if (freq[0] % 2 != 0)
        return false;
    for (int i = 1; i <= k / 2; i++)
    {
        if (freq[i] != freq[k - i])
            return false;
    }
    return true;
}
int main()
{
    int size, k;
    vector<int> arr;
    cin >> size >> k;
    while (size)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        size--;
    }
    cout << canArrange(arr, k);
    return 0;
}