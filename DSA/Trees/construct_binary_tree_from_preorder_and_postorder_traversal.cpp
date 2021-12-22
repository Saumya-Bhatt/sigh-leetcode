#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// low and high are w.r.t to postorder
TreeNode *helper(vector<int> &preorder, vector<int> &postorder, int *preIndex, int low, int high)
{

    // Base case
    if (*preIndex >= preorder.size() || low > high)
        return nullptr;

    // first node in preorder is the root
    TreeNode *node = new TreeNode(preorder[*preIndex]);
    ++*preIndex;

    // is a leaf node (no children)
    if (low == high)
        return node;

    // search next element of pre[] in post[]
    int i;
    for (i = low; i <= high; i++)
    {
        if (preorder[*preIndex] == postorder[i])
            break;
    }

    // ith is the root | [l:i] is the left subtree | [i+1,high-1] is the right subtree
    // taking high-1, since high is the root (postorder)
    node->left = helper(preorder, postorder, preIndex, low, i);
    node->right = helper(preorder, postorder, preIndex, i + 1, high);
    return node;
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int preIndex = 0;
    return helper(preorder, postorder, &preIndex, 0, preorder.size() - 1);
}