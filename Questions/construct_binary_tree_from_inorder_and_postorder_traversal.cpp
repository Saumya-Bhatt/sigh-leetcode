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

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int postEnd = postorder.size() - 1;
    int inStart = 0;
    int inEnd = inorder.size() - 1;
    return helper(postEnd, inStart, inEnd, inorder, postorder);
}

// postorder = L R D
// inorder = L D R

TreeNode *helper(int &postEnd, int inStart, int inEnd, vector<int> &inorder, vector<int> &postorder)
{
    if (postEnd < 0 || inStart > inEnd)
        return NULL;

    TreeNode *result = new TreeNode(postorder[postEnd]);

    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == result->val)
            inIndex = i;
    }
    postEnd--;

    result->right = helper(postEnd, inIndex + 1, inEnd, inorder, postorder);
    result->left = helper(postEnd, inStart, inIndex - 1, inorder, postorder);
    return result;
}