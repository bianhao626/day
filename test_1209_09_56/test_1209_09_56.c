#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

//BM13 判断一个链表是否为回文结构
struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
bool isPail(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    //找到中间的点
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    //反转链表
    struct ListNode* tmp = reverse(slow);
    //进行比较
    while (tmp)
    {
        if (tmp->val == head->val)
        {
            head = head->next;
            tmp = tmp->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}
//BM15 删除有序链表中重复的元素-I
//struct ListNode* deleteDuplicates(struct ListNode* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* cur = head;
//    struct ListNode* tmp = head;
//    while (tmp)
//    {
//        if (cur->val != tmp->val)
//        {
//            cur->next = tmp;
//            cur = cur->next;
//        }
//        tmp = tmp->next;
//    }
//    return head;
//}
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* cur = head;
    struct ListNode* tmp = head->next;
    while (cur && tmp)
    {
        if (cur->val == tmp->val)
        {
            tmp = tmp->next;
            cur->next = tmp;
        }
        else
        {
            cur = cur->next;
            tmp = tmp->next;
        }
    }
    return head;
}


int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node8 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node9 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node10 = (struct ListNode*)malloc(sizeof(struct ListNode));

	node1->val = 1;
	node2->val = 1;
	node3->val = 2;
	node4->val = 4;
	node5->val = 5;
	node6->val = 4;
	node7->val = 3;
	node8->val = 2;
	node9->val = 1;
	node10->val = 1;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = node10;
	node10->next = NULL;

    /*bool tmp = isPail(node1);*/
    struct ListNode* tmp = deleteDuplicates(node1);
	return 0;
}