//===========================================================

// 1. Whenever a new Node is added to the binary tree, the address of the node is pushed into a queue.
// 2. A Node address will stay in the queue until both its children’s Nodes do not get filled.
// 3. Once both the children’s Nodes get filled up, the parent Node is popped from the queue.
// Here is the code to perform the above mentioned data entry.

//===========================================================

#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// helper function to create node
void createNode(Node **root, int i, queue<Node *> q)
{
    Node *node = new Node(i);

    // if root hasn't been created, build the root
    if (root == nullptr)
    {
        *root = node;
    }
    else if (q.front()->left == nullptr)
    {
        // left child of the node is availabe to add
        q.front()->left = node;
    }
    else
    {
        // since only right child left, we will insert it there
        // After this, the parent node, has no more children left, so we will pop it from the queue
        q.front()->right = node;
        q.pop();
    }

    // Whenever a new Node is added to the tree, its
    // address is pushed into the queue.
    // So that its children Nodes can be used later.
    q.push(node);
    return;
}

// main function
Node *createTree(int arr[], int n)
{
    Node *root = nullptr;
    queue<Node *> q;
    for (int i = 0; i < n; i++)
    {
        createNode(&root, arr[i], q);
    }
    return root;
}
