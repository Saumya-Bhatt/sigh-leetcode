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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return nullptr;
    int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
    TreeNode *node = new TreeNode(val);
    node->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
    node->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
    return node;
}