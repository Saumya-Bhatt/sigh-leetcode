#include <iostream>
#include <vector>
using namespace std;
int pathInATree(int n, vector<int> &nums, vector<string> queries)
{
    int root=n%2==0?n/2:(n+1)/2;
    for(int i=0;i<nums.size();i++){
        int num=nums[i];
        string query=queries[i];
        for(auto q:query){
            if(q=='U'){
                
            }
        }
    }
}
int main()
{
    int n, query_num;
    vector<int> num_start;
    vector<string> queries;
    cin >> n >> query_num;
    while (query_num)
    {
        int temp;
        string tmp;
        cin >> temp;
        cin >> tmp;
        num_start.push_back(temp);
        queries.push_back(tmp);
        query_num--;
    }
    cout << pathInATree(n, num_start, queries);
    return 0;
}