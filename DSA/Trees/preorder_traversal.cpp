
// <root><left><right>

#include <iostream>
#include <stack>
#include <stdio.h>
#include <stddef.h>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
    Node(char val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// using recursion
void preorder_using_recursion(Node *root)
{
    if (root == NULL)
        return;
    printf("%c", root->data);
    preorder_using_recursion(root->left);
    preorder_using_recursion(root->right);
}

// using iterative method - stacks
void preorder_using_stacks(Node *root)
{
    stack<Node *> S;
    S.push(root);

    while (!S.empty())
    {
        Node *curr = S.top();
        printf("%d", curr->data);
        S.pop();
        if (curr->right != NULL)
        {
            S.push(curr->right);
        }
        if (curr->left != NULL)
        {
            S.push(curr->left);
        }
    }
}