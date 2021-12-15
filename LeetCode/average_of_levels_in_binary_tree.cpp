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

vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *node;
    double numNodes;
    while (!q.empty())
    {
        numNodes = q.size();
        double levelSum = 0;
        for (int i = 0; i < numNodes; i++)
        {
            node = q.front();
            q.pop();
            levelSum += node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(levelSum / numNodes);
    }
    return ans;
}