#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

//牛客网BM7
struct ListNode* EntryNodeOfLoop(struct ListNode* pHead)
{
    struct ListNode* slow = pHead;
    struct ListNode* fast = pHead;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            struct ListNode* tmp = pHead;
            while (tmp != fast)
            {
                tmp = tmp->next;
                fast = fast->next;
            }
            return tmp;
        }
    }
    return NULL;
}

//BM8
//方法一
struct ListNode* FindKthToTail(struct ListNode* pHead, int k)
{
    if (pHead == NULL)
    {
        return NULL;
    }
    int len = 1;
    struct ListNode* cur = pHead;
    while (cur->next)
    {
        cur = cur->next;
        len++;
    }
    if (len < k)
    {
        return NULL;
    }
    cur = pHead;
    for (int i = 0; i < len - k; i++)
    {
        cur = cur->next;
    }
    return cur;
}
//方法二
struct ListNode* FindKthToTail(struct ListNode* pHead, int k)
{
    if (pHead == NULL)
    {
        return NULL;
    }
    int i = 0;
    struct ListNode* head, * tail;
    head = tail = pHead;
    while (head)
    {
        if (i < k)
        {
            i++;
        }
        else if (i == k)
        {
            tail = tail->next;
        }
        head = head->next;
    }

    if (i == k)
    {
        return tail;
    }
    return NULL;
}