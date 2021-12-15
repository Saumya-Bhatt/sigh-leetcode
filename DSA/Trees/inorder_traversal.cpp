// <left><root><right>

#include <stdio.h>
#include <iostream>
#include <stack>
#include <stddef.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// using recursion
void inorder_using_recursion(Node *root)
{
    if (root == NULL)
        return;
    inorder_using_recursion(root->left);
    printf("%d", root->data);
    inorder_using_recursion(root->right);
}

// using stacks - iterative method
void inorder_using_stacks(Node *root)
{
    stack<Node *> S;
    Node *curr = root;
    while (curr != NULL || !S.empty())
    {

        // reaching the left most node of the root
        while (curr != NULL)
        {
            S.push(curr);
            curr = curr->left;
        }

        // curr is NUll (of the leftmost leaf)
        curr = S.top(); // left most leaf node
        S.pop();
        cout << curr->data << ' ';

        // have visited the node and it's left sub tree.
        // now moving onto right sub tree
        curr = curr->right;
    }
}