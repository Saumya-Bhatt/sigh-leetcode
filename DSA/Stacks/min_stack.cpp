// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{

    stack<int> data;
    stack<int> min;

public:
    void push(int x)
    {
        data.push(x);
        if (min.empty())
        {
            min.push(x);
        }
        else
        {
            if (x <= min.top())
            {
                min.push(x);
            }
        }
    }

    void pop()
    {
        if (!min.empty())
        {
            if (data.top() == min.top())
            {
                min.pop();
            }
            data.pop();
        }
    }

    int top()
    {
        return data.top();
    }

    int getMin()
    {
        return min.top();
    }
};