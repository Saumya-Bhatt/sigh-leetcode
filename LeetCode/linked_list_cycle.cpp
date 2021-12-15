using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // 1 hop
        fast = fast->next->next; // 2 hop
        if (slow == fast)
            return true; // fast caught up to slow, so there is a loop
    }
    // fast reached null, so the list terminates
    return false;
}