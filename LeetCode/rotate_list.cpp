using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{

    // edge cases
    if (head == nullptr || head->next == nullptr)
        return head;

    int listSize = 1;
    ListNode *tail = head;

    // tail is at the last node
    // we get LL size;
    while (tail->next != nullptr)
    {
        listSize++;
        tail = tail->next;
    }

    // chaining the LL into a cycle
    tail->next = head;

    // new index as can be case where k>listSize
    int newHeadIndex = listSize - k % listSize;

    // tail is currently at the last node
    // will move it to node just before the newHeadIndex
    for (int i = 0; i < newHeadIndex; i++)
    {
        tail = tail->next;
    }

    // tail currently at node just before newHeadIndex
    // so doing ->next is the required new head
    head = tail->next;

    // currently our LL is cyclic
    // tail is the last element of our rotated LL
    // so need to break it's connection with head
    tail->next = nullptr;

    return head;
}