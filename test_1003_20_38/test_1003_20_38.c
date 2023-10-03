#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* deleteNodes(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* p1 = head;
    struct ListNode* p2 = head->next;

    while (p2->next)
    {
        if (p1->val < p2->val && p2->val > p2->next->val)
        {
            p1->next = p2->next;
            p2 = p2->next;
        }
        else
        {
            p1 = p2;
            p2 = p1->next;
        }
    }
    return head;
}