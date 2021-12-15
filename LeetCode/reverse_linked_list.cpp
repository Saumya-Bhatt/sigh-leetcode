using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *previous = nullptr;
    ListNode *current = head;
    ListNode *following = head->next;
    while (current != nullptr)
    {
        current->next = previous; // reversing the direction of current to point to previous
        previous = current;       // rn current is ahead of previous, we want to keep previous as the head of our new LL, so changing it to current
        current = following;      // keeps memory of what's ahead since can't use current->next
        if (following != nullptr)
        { // if following is nullptr, won't run this, making current as nullptr and getting out of loop.
            following = following->next;
        }
    }
    head = previous;
    return head;
}