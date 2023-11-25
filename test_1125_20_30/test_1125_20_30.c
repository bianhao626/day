#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    if (head == NULL || head->next == NULL || k < 2)
    {
        return head;
    }
    int count = 1;
    struct ListNode* tmp = head;
    while (tmp->next != NULL)
    {
        count++;
        tmp = tmp->next;
    }

    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = head;
    struct ListNode* pre = NULL;
    struct ListNode* cur = newhead;
    struct ListNode* next = NULL;

    int n = count / k;
    while (n--)
    {
        pre = cur;
        cur = cur->next;
        for (int i = 1; i < k; i++)
        {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
    }
    return newhead->next;
}

int main()
{
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    //struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    //node4->val = 7;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    //node4->next = NULL;

    struct ListNode* tmp = reverseKGroup(node1, 3);
    return 0;
}