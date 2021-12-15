#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}

// Driver Code
int main()
{
    queue<int> q;
    if (q.empty())
    {
        cout << "Queue q is empty.\n";
    }
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "The queue q is : ";
    showq(q);

    cout << "\nq.size() : " << q.size();
    cout << "\nq.front() : " << q.front();
    cout << "\nq.back() : " << q.back();

    q.pop();
    cout << "\nQueue q after q.pop() : ";
    showq(q);

    return 0;
}