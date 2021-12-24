// ============================================================

//   Input: parent[] = {1, 5, 5, 2, 2, -1, 3}
//   Output: root of below tree
//           5
//         /  \
//        1    2
//       /    / \
//      0    3   4
//          /
//         6
//  Explanation:
//  Index of -1 is 5.  So 5 is root.
//  5 is present at indexes 1 and 2.  So 1 and 2 are children of 5.
//  1 is present at index 0, so 0 is child of 1.
//  2 is present at indexes 3 and 4.  So 3 and 4 are children of 2.
//  3 is present at index 6, so 6 is child of 3.

// ============================================================

// 1. Create an array of pointers say created[0..n-1]. The value of created[i] is NULL if node for index i is not created, else value is pointer to the created node.
// 2. Do following for every index i of given array

// createNode(parent[], i, created[])

// 3. If created[i] is not NULL, then node is already created. So return.
// Create a new node with value ‘i’.
// 4. If parent[i] is -1 (i is root), make created node as root and return.
// 5. Check if parent of ‘i’ is created (We can check this by checking if created[parent[i]] is NULL or not.
// 6. If parent is not created, recur for parent and create the parent first.
// 7. Let the pointer to parent be p. If p->left is NULL, then make the new node as left child. Else make the new node as right child of parent.

// ============================================================

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// helper function to create a node with value 'i'
void createNode(int parent[], int i, Node *created[], Node **root)
{

    // if already created, return
    if (created[i] != nullptr)
        return;

    // else create a new node
    Node *node = new Node(i);
    created[i] = node;

    // check if it is root. If so make, it
    if (parent[i] == -1)
    {
        *root = node;
        return;
    }

    // if the parent of the current node is not created, create it first
    if (created[parent[i]] == nullptr)
    {
        createNode(parent, parent[i], created, root);
    }

    // now that the parent has been created, find the pointer to it
    Node *p = created[parent[i]];

    // if the parent's left child is NULL, assign the current node to it'sleft. Else right
    if (p->left == nullptr)
    {
        p->left = node;
    }
    else
    {
        p->right = node;
    }
}

// main function
Node *createTree(int parent[], int n)
{

    // create array created[] initialized to NULL to keep track of what all nodes were created
    Node *created[n];
    for (int i = 0; i < n; i++)
    {
        created[i] = nullptr;
    }

    Node *root = nullptr;

    // initializing the node building for each element of the array
    for (int i = 0; i < n; i++)
    {
        createNode(parent, i, created, &root);
    }

    return root;
}