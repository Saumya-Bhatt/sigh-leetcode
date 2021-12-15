using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head)
        return nullptr;
    ListNode newHead(-1);
    ListNode *slow = &newHead;
    ListNode *fast = &newHead;
    newHead.next = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *toBeDeleted = slow->next;
    slow->next = slow->next->next;
    delete toBeDeleted;
    return newHead.next;
}
