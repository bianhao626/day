#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};




//BM11 链表相加(二)
//用例只适用于一些简单的案例，过长案例不适用
int ListNodeSize(struct ListNode* head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 1;
    while (head->next)
    {
        head = head->next;
        count++;
    }
    return count;
}

struct ListNode* CreatNewNode(int x)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = x;
    node->next = NULL;
    return node;
}

struct ListNode* addInList(struct ListNode* head1, struct ListNode* head2)
{
    int len1 = ListNodeSize(head1);
    int len2 = ListNodeSize(head2);
    struct ListNode* p1 = head1;
    struct ListNode* p2 = head2;
    int sum1 = 0;
    int sum2 = 0;
    while (p1)
    {
        len1--;
        sum1 += pow(10, len1) * (p1->val);
        p1 = p1->next;
    }
    while (p2)
    {
        len2--;
        sum2 += pow(10, len2) * (p2->val);
        p2 = p2->next;
    }
    int sum = sum1 + sum2;
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = NULL;
    while (sum)
    {
        int tmp = sum % 10;
        struct ListNode* node = CreatNewNode(tmp);
        node->next = newhead->next;
        newhead->next = node;
        sum /= 10;
    }
    return newhead->next;
}




int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->val = 9;
	node2->val = 3;
	node3->val = 7;

    node4->val = 6;
    node5->val = 3;

	node1->next = node2;
	node2->next = node3;
    node3->next = NULL;

    node4->next = node5;
    node5->next = NULL;

	struct ListNode* tmp = addInList(node1, node4);
	return 0;
}