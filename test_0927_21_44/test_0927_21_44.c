#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2) {
    // write code here
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* pHead = p;//��pHead��p������
    if (pHead1 == NULL && pHead2 == NULL)
        return pHead1;
    else if (pHead1 == NULL && pHead2 != NULL)
        return pHead2;
    else if (pHead1 != NULL && pHead2 == NULL)
        return pHead1;
    while (pHead1 != NULL && pHead2 != NULL)
    {
        if (pHead1->val < pHead2->val)
        {
            p->next = pHead1;
            p = p->next;
            pHead1 = pHead1->next;
        }
        else
        {
            p->next = pHead2;
            p = p->next;
            pHead2 = pHead2->next;
        }
    }
    if (pHead1 == NULL)
    {
        p->next = pHead2;
    }
    else if (pHead2 == NULL)
    {
        p->next = pHead1;
    }
    return pHead->next;
}


struct ListNode {
    int val;
    struct ListNode* next;
};
bool hasCycle(struct ListNode* head) {
    //����ָ��
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != NULL && slow != NULL)
    {
        if (fast->next != NULL)
        {
            fast = fast->next->next; //��ָ��ÿ��2��
        }
        else
        {
            return false;
        }
        slow = slow->next; //��ָ��ÿ��1��
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}