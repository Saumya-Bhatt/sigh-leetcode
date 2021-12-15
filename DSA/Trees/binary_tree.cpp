#include <stddef.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int main()
{

    // create root node of val 1
    // left child is 2
    // right child is 3
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    // left grand child as 4
    root->left->left = new Node(4);

    return 0;
}