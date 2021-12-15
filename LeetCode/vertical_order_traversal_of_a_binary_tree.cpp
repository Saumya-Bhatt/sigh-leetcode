#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void dfs(vector<vector<int>> &nodes, TreeNode *root, int x, int y)
{
    if (!root)
        return;
    nodes.push_back({x, y, root->val});
    if (root->left)
        dfs(nodes, root->left, x - 1, y + 1);
    if (root->right)
        dfs(nodes, root->right, x + 1, y + 1);
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    vector<vector<int>> nodes;          //{level_x, level_y, node_value}
    dfs(nodes, root, 0, 0);             // root starting at 0,0 on grid
    map<int, vector<vector<int>>> data; // stores all vertical nodes and their value all of whom have similar level_x
    for (auto i : nodes)
    {
        data[i[0]].push_back({i[1], i[2]}); // x = {y,val}
    }
    map<int, vector<vector<int>>>::iterator it = data.begin();
    while (it != data.end())
    {
        auto curr = it->second;
        vector<int> temp;
        sort(curr.begin(), curr.end()); // will sort by y in {y,val}
        for (auto i : curr)
        {
            temp.push_back(i[1]); // storing {val}
        }
        ans.push_back(temp);
        it++;
    }
    return ans;
}