#include "test_1116_15_03.h"

void SLTPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->value);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* CreateNode(SLNDateType x)
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

void SLTPushBack(SLNode** pphead, SLNDateType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);
	if (*pphead == NULL)
	{
		//链表为空的时候
		*pphead = newnode;
		//改变的是结构体的指针，所以使用二级指针
	}
	else
	{
		//链表不为空的时候，找尾
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
		//改变的是结构体的内容
	}
}

void SLTPushFront(SLNode** pphead, SLNDateType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* pre = NULL;
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			pre = tail;
			tail = tail->next;
		}

		pre->next = tail->next;
		free(tail);
	}
}

void SLTPopFront(SLNode** pphead)
{
	assert(*pphead);

	SLNode* cur = *pphead;
	*pphead = cur->next;
	free(cur);
}

SLNode* SLTFind(SLNode* phead, SLNDateType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->value == x)
		{
			break;
		}
		cur = cur->next;
	}
	return cur;
}

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDateType x)
{
	assert(pphead);
	assert(*pphead);//两者都为空，或者两者都不是空
	assert(pos);
	//SLNode* newnode = CreateNode(x);

	//SLNode* pre = NULL;
	//SLNode* cur = *pphead;

	//如果是在第一个节点进行插入，相当于是头插法（无论链表是只有一个还是有多个节点）
	//while (cur->value != pos->value)
	//{
	//	pre = cur;
	//	cur = cur->next;
	//}
	//if (pre == NULL)
	//{
	//	newnode->next = cur;
	//	*pphead = newnode;
	//}
	//else
	//{
	//	newnode->next = cur;
	//	pre->next = newnode;
	//}

	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLNode* pre = *pphead;
		while (pre->value != pos->value)
		{
			pre = pre->next;
		}
		SLNode* newnode = CreateNode(x);
		pre->next = newnode;
		newnode->next = pos;
	}
}

void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	SLNode* pre = NULL;
	SLNode* cur = *pphead;

	while (cur->value != pos->value)
	{
		pre = cur;
		cur = cur->next;
	}
	if (pre == NULL)
	{
		*pphead = cur->next;
		free(cur);
	}
	else
	{
		pre->next = cur->next;
		free(cur);
	}
}

void SLTDestroy(SLNode** pphead)
{
	assert(pphead);
	//assert(*pphead);

	SLNode* cur = *pphead;
	while (*pphead)
	{
		*pphead = cur->next;
		free(cur);
		cur = *pphead;
	}
}