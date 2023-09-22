#include <stdio.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* ReverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;
    struct ListNode* cur = head;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* H = malloc(sizeof(struct ListNode));
    H->next = head;
    struct ListNode* p, * tmp, * cur = H;
    for (int i = 0; i < m - 1; i++)
    {
        cur = cur->next;
    }
    tmp = cur;
    struct ListNode* q;
    cur = cur->next;
    q = cur;
    for (int i = 0; i < n - m + 1; i++)
    {
        //ͷ�巨
        p = cur;
        cur = cur->next;
        p->next = tmp->next;
        tmp->next = p;
    }
    q->next = cur;
    return H->next;
}