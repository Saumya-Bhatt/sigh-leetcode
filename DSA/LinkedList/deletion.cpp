#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// Deletes the node with given value and returns head.
// head- pointer to head of Linked List
// data - data value of node to be deleted
struct Node *deleteNodeWithValue(struct Node *head, int key)
{
    // Store head node
    Node *current, *prev = head;
    // If head node itself holds the key to be deleted
    if (current != NULL && current->data == key)
    {
        head = current->next; // Changed head
        free(current);        // free old head
        return;
    }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }
    // If key was not present in linked list
    if (current == NULL)
        return;
    // Unlink the node from linked list
    prev->next = current->next;
    free(current); // Free memory
}