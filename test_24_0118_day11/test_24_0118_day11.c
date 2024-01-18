#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

//NC21 链表内指定区间反转
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
        //头插法
        p = cur;
        cur = cur->next;
        p->next = tmp->next;
        tmp->next = p;
    }
    q->next = cur;
    return H->next;
}

//1171. 从链表中删去总和值为零的连续节点
struct ListNode* removeZeroSumSublists(struct ListNode* head)
{
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->next = head;
    struct ListNode* p = tmp, * q = tmp;
    int sum = 0;
    while (p)
    {
        sum = 0;
        q = p->next;
        while (q)
        {
            sum -= q->val;
            if (sum == 0)
            {
                p->next = q->next;
            }
            q = q->next;
        }
        p = p->next;
    }
    return tmp->next;
}

int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->val = 1;
	node2->val = 2;
	node3->val = 3;
	node4->val = 4;
    node5->val = 5;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
    node5->next = NULL;

    struct ListNode* tmp = reverseBetween(node1, 2, 4);
	return 0;
}