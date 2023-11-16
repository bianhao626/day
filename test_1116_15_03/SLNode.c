#include "test_1116_15_03.h"

void SLTPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

SLNode* CreateNode(SLNDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	newnode->value = x;
	newnode->next = NULL;
	return newnode;
}

void SLTPushBack(SLNode* phead, SLNDataType x)
{
	if (phead == NULL)
	{
		//链表为空的时候
	}
	else
	{
		//链表不为空的时候，找尾
		SLNode* tail = phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		SLNode* newnode = CreateNode(x);
		tail->next = newnode;
	}
}