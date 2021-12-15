// using 2 stacks
// initially when both stacks are empty, just add initial element to stack 1
// when next element is added, move first element into stack2.
// then when the new element is added into stack 1, pop the element from stack 2 and push it into stack 1
// doing this will ensure, first added element is always at the top

#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1, s2;

    void enqueue(int x)
    {

        // move all elements from s1 to s2;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // push latest item into s1
        s1.push(x);

        // push back everything back from s2 to s1;
        while (!s2.empty())
        {
            s1.push(s2.top());
            s1.pop();
        }
    }

    int dequeue()
    {
        if (s1.empty())
            exit(0);
        int x = s1.top();
        return x;
    }
};