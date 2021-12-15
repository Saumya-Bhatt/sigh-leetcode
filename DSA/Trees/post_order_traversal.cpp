
// <left><right><root>

#include <iostream>
#include <stddef.h>
#include <stack>
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

// using recursion
void postorder_using_recursion(Node *root)
{
    if (root == NULL)
        return;
    postorder_using_recursion(root->left);
    postorder_using_recursion(root->right);
    printf("%d", root->data);
}

// using iterative method - stacks
void postorder_using_stacks(Node *root)
{
    stack<Node *> S;
    Node *curr = root;

    if (root == NULL)
        return;

    stack<Node *> s1, s2;
    Node *node;
    s1.push(root);

    // pushing <root><right><left> in s2
    while (!s1.empty())
    {
        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left != NULL)
        {
            s1.push(node->left);
        }
        if (node->right != NULL)
        {
            s1.push(node->right);
        }
    }

    // using LIFO property of stack to print in <left><right><root> manner
    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        printf("%d", node->data);
    }
}