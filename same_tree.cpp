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
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true; // both are leaf nodes
    if (!p || !q)
        return false; // one of them is leaf node other not
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}