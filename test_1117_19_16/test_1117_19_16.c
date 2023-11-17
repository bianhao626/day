#include <stdio.h>
#include <stdlib.h>

struct ListNode
{     
	int val;    
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        if (cur->val == val)
        {
            struct ListNode* next = cur->next;
            if (pre)
            {
                //如果当前节点的前一个节点不是空，那么就正常指向就可以
                pre->next = next;
            }
            else
            {
                //如果当前节点的前一个是空，那么需要更新头节点
                head = next;
            }
            free(cur);
            cur = next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
    struct ListNode* slow = pListHead, * fast = pListHead;
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->val = 7;
	node2->val = 7;
	node3->val = 7;
	node4->val = 7;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

    struct ListNode* tmp = removeElements(node1, 7);
	return 0;
}