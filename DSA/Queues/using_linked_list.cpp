#include <bits/stdc++.h>
using namespace std;

// structure for node
struct QNode
{
    int data;
    QNode *next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

// structure for Queue
struct Queue
{
    QNode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int x)
    {
        QNode *toBeAddedAtRear = new QNode(x);

        // if queue is empty, new node is both front and rear
        if (rear == NULL)
        {
            front = rear = toBeAddedAtRear;
        }

        // add node at rear and change it
        rear->next = toBeAddedAtRear;
        rear = toBeAddedAtRear;
    }

    int dequeue()
    {

        // if queue is empty. return nothing
        if (front == NULL)
            return;

        QNode *posFirst = front;
        front = posFirst->next;
        int prevFirstItem = posFirst->data;
        delete (posFirst);
        return prevFirstItem;
    }
};
