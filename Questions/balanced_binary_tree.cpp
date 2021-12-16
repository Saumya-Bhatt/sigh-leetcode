#include <algorithm>
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
int maxDepth(TreeNode *root, bool &balanced)
{
    if (root == nullptr)
        return 0;
    int left = maxDepth(root->left, balanced);
    int right = maxDepth(root->right, balanced);
    if (abs(left - right) > 1)
        balanced = false;
    return 1 + max(left, right);
}
bool isBalanced(TreeNode *root)
{
    bool ans = true;
    maxDepth(root, ans);
    return ans;
}