#include <iostream>
using namespace std;

class Deque
{
    int front, rear, size, *arr;

    Deque(int s)
    {
        front = -1;
        rear = 0;
        size = s;
        arr = new int[s];
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front = rear + 1))
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

    void insertFront(int x)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }

        // used when inserting element first since deque initialization
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        // used for rest all cases
        else
        {
            front = (front - 1) % size;
        }
        arr[front] = x;
        cout << "Inserted at front : " << x << endl;
    }

    void insertRear(int x)
    {
        if (isFull())
        {
            cout << "Overfloe\n";
            return;
        }
        // used when inserting element first since deque initialization
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        // used for rest all cases
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = x;
        cout << "Inserted at rear : " << x << endl;
    }

    int deleteFront()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return -1;
        }
        int removedElement = arr[front];

        // reset arr when only single element was left and that was dequeued
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

    int deleteRear()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return -1;
        }
        int removedElement = arr[rear];

        // reset arr when only single element was left and that was dequeued
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1) % size;
        }
        return removedElement;
    }
};