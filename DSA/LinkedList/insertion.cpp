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

Node *insertAtBegining(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node *insertAtEnd(Node *head, int val)
{
    Node *newNode = new Node(val);
    Node *current = head;
    if (current == nullptr)
    {
        head = newNode;
    }
    else
    {
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// 1 base indexing
// Inserts a new node (new) at position n and returns head.
// head- pointer to the head of the Linked List
// data - data value of newNode
// n - position for insertion n>=1
Node *insertAtPosition(Node *head, int val, int pos)
{
    Node *newNode = new Node(val);
    Node *previous = head; // pred will point to predecessor of newNode

    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }
    // find the n-1 node (predecessor): decrement and move forward in the list
    // until either the list has ended or n becomes 0
    while (--pos && previous != nullptr)
    {
        previous = previous->next;
    }
    if (previous == nullptr)
        return nullptr;
    // if it is not NULL, insert new after its predecessor
    newNode->next = previous->next;
    previous->next = newNode;
    return head;
}