using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *currA = headA;
    ListNode *currB = headB;
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    while (currA != currB)
    {
        // If one of them reaches the end earlier then reuse it
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning,
        // they will be equidistant from the collision point.
        currA = (currA == nullptr) ? headB : currA->next;
        currB = (currB == nullptr) ? headA : currB->next;
    }
    return currA;
}