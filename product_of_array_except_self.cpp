#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    int size = nums.size();
    int leftProd[size];
    int rightProd[size];
    vector<int> ansProd(size);

    leftProd[0] = 1;
    rightProd[size - 1] = 1;

    for (int i = 1; i < size; i++)
    {
        leftProd[i] = leftProd[i - 1] * nums[i - 1];
        rightProd[size - i - 1] = rightProd[size - i] * nums[size - i];
    }
    for (int i = 0; i < size; i++)
    {
        ansProd[i] = leftProd[i] * rightProd[i];
    }
    return ansProd;
}
int main()
{
    int size;
    vector<int> nums;
    cin >> size;
    while (size)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
        size--;
    }
    vector<int> ans = productExceptSelf(nums);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}