#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2) {
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }
    struct ListNode* p = NULL;
    if (pHead1->val <= pHead2->val)
    {
        p = pHead1;
        pHead1 = pHead1->next;
    }
    else
    {
        p = pHead2;
        pHead2 = pHead2->next;
    }

    struct ListNode* q = p;
    while (pHead1 != NULL && pHead2 != NULL)
    {
        if (pHead1->val <= pHead2->val)
        {
            q->next = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            q->next = pHead2;
            pHead2 = pHead2->next;
        }
        q = q->next;
    }
    if (pHead1 != NULL)
    {
        q->next = pHead1;
    }
    if (pHead2 != NULL)
    {
        q->next = pHead2;
    }
    return p;
}
