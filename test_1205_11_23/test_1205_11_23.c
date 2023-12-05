#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

//BM9 删除链表的倒数第n个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	tmp->next = head;
	struct ListNode* p1 = tmp, * p2 = tmp;
	while (n--)
	{
		p1 = p1->next;
	}
	while (p1->next)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	struct ListNode* cur = p2->next;
	p2->next = cur->next;
	return tmp->next;
}

//BM10 两个链表的第一个公共结点
int ListNodeSize(struct ListNode* head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 1;
    while (head->next) {
        head = head->next;
        count++;
    }
    return count;
}
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2) {
    int len1 = ListNodeSize(pHead1);
    int len2 = ListNodeSize(pHead2);
    int tmp = 0;
    if (len1 > len2)
    {
        tmp = len1 - len2;
        while (tmp--) {
            pHead1 = pHead1->next;
        }
    }
    else {
        tmp = len2 - len1;
        while (tmp--) {
            pHead2 = pHead2->next;
        }
    }
    while (pHead1 || pHead2) {
        if (pHead1 == pHead2) {
            return pHead1;
        }
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
    }
    return NULL;
}


int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->val = 1;
	node2->val = 2;
	node3->val = 3;
	node4->val = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

    struct ListNode* tmp = removeNthFromEnd(node1, 2);
	return 0;
}
