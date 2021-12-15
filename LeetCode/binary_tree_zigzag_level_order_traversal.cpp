#include <vector>
#include <queue>
#include <deque>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    bool leftToRight = true;
    deque<TreeNode *> q{root};
    TreeNode *node;
    while (!q.empty())
    {
        vector<int> sublevel;
        int numNodes = q.size();
        for (int i = 0; i < numNodes; i++)
        {
            if (leftToRight)
            {
                node = q.front();
                q.pop_front();
                if (node->left != nullptr)
                    q.push_back(node->left);
                if (node->right != nullptr)
                    q.push_back(node->right);
            }
            else
            {
                node = q.back();
                q.pop_back();
                if (node->right != nullptr)
                    q.push_front(node->right);
                if (node->left != nullptr)
                    q.push_front(node->left);
            }
            sublevel.push_back(node->val);
        }
        ans.push_back(sublevel);
        leftToRight = !leftToRight;
    }
    return ans;
}