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

void print(Node *head)
{
    struct Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << endl;
        current = current->next;
    }
    return;
}