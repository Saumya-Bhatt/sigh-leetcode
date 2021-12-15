using namespace std;
struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *llist)
{
    if (llist == nullptr)
        return llist;
    SinglyLinkedListNode *p1 = llist->next;
    SinglyLinkedListNode *p2 = llist;
    while (p1 != nullptr)
    {
        if (p1->data == p2->data)
        {
            p2->next = p1->next;
        }
        else
        {
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return llist;
}