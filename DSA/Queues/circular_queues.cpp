#include <iostream>
using namespace std;

class Queue
{

    int front, rear;

    // circular queue
    int size, *arr;

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    bool isFull()
    {
        if (front == 0 && rear == size - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    void enQueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Inserted : " << x << endl;
        }
    }

    // deQueuing does not mean we are deleting the element from the array
    // we are just changing the pointers, the element in the array remain
    // it is just that when pointers are changed, when enQueing, they get overridden
    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int removedElement = arr[front];

        // queue has only 1 element so reset it after removing it
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return removedElement;
    }
};