#include <bits/stdc++.h>
using namespace std;

// structure for queue
class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// creates queue of given capacity
// initialized with size 0
Queue *createQueue(unsigned capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;

    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;

    queue->array = new int[queue->capacity];
    return queue;
};

// is full when size equals capacity
bool isFull(Queue *queue)
{
    return queue->size == queue->capacity;
};

// is empty when size is 0
bool isEmpty(Queue *queue)
{
    return queue->size == 0;
};

// enquing item to the queue
// is added at the back
void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
        return;

    // to make sure queue does not overflow
    queue->rear = (queue->rear + 1) % queue->capacity;

    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;

    cout << item << " enqueued to queue\n";
}

// dequeing item from queue
// is removed from the front
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return;

    int first_item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return first_item;
}

// getting front item of queue
int front(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// getting rear of queue
int rear(Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}