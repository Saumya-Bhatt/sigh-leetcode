#include <vector>
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

void dfs(TreeNode *root, vector<int> &store)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        store.push_back(root->val);
    dfs(root->left, store);
    dfs(root->right, store);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> treeA;
    vector<int> treeB;
    dfs(root1, treeA);
    dfs(root2, treeB);
    if (treeA.size() != treeB.size())
        return false;
    for (int i = 0; i < treeA.size(); i++)
    {
        if (treeA[i] != treeB[i])
            return false;
    }
    return true;
}