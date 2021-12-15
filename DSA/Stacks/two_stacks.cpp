// Create a data structure TwoStacks that represents two stacks using only one Array, i.e., both stacks should use the same array for storing elements.

// Following functions must be supported by TwoStacks:

// push1(int x) :- pushes x to first stack
// push2(int x) :- pushes x to second stack
// pop1() :- pops an element from first stack and returns the popped element
// pop2() :- pops an element from second stack and returns the popped element

#include <iostream>
using namespace std;

class TwoStack
{

    int *arr;
    int size;
    int top1, top2;

public:
    // constructor
    TwoStack(int x)
    {
        size = x;
        arr = new int[x];
        top1 = -1;
        top2 = size;
    }

    // method 1 : push to stack 1
    void push1(int x)
    {
        // must be space of at least one to push the item
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "stack overflow";
            exit(1);
        }
    }

    // method 2 : push to stack 2
    void push2(int x)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "stack overflow";
            exit(1);
        }
    }

    // method 3 : pop from stack 1
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout << "stack underflow";
            exit(1);
        }
    }

    // method 4 : pop from stack 2
    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            cout << "stack underflow";
            exit(1);
        }
    }
};