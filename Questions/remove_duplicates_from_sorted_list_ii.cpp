using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{

    // creating a dummy LL starting with -101
    ListNode dummy(-101);
    dummy.next = head;

    // prev points to start of dummy
    // curr points to head which is next to start of dummy
    ListNode *prev = &dummy;
    ListNode *curr = head;

    while (curr != nullptr)
    {

        // skipping all similar elements
        // curr points to upper bound of similar
        while (curr->next != nullptr && curr->val == curr->next->val)
        {
            curr = curr->next;
        }

        if (prev->next == curr)
        {
            // if same, don't attach to dummy
            // skip it
            prev = prev->next;
        }
        else
        {
            // else add it to dummy
            prev->next = curr->next;
        }

        curr = curr->next;
    }
    return dummy.next;
}