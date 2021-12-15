#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> q;
    TreeNode *node;
    q.push(root);
    int numChildNodes;
    while (!q.empty())
    {
        numChildNodes = q.size();
        vector<int> sublevel;
        for (int i = 0; i < numChildNodes; i++)
        {
            node = q.front();
            q.pop();
            sublevel.push_back(node->val);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        ans.push_back(sublevel);
    }
    return ans;
}