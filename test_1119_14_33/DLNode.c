#include "test_1119_14_33.h"

DLNode* InitDL()
{
	DLNode* phead = DLCreateNode(-1);
	phead->pre = phead;
	phead->next = phead;

	return phead;
}

void DLPrint(DLNode* phead)
{
	assert(phead);

	printf("哨兵<=>");
	DLNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->val);
		cur = cur->next;
	}
	printf("哨兵\n");
}

DLNode* DLCreateNode(DLTDataType x)
{
	DLNode* newnode = (DLNode*)malloc(sizeof(DLNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	newnode->val = x;
	newnode->pre = newnode;
	newnode->next = newnode;
	return newnode;
}

void DLPushBack(DLNode* phead, DLTDataType x)
{
	assert(phead);

	DLNode* tail = phead->pre;
	DLNode* newnode = DLCreateNode(x);

	//尾插
	newnode->next = phead;
	tail->next = newnode;
	newnode->pre = tail;
	phead->pre = newnode;
}

void DLPopBack(DLNode* phead)
{
	assert(phead);
	//不可以删除哨兵
	assert(phead->next != phead);

	DLNode* tail = phead->pre;

	phead->pre = tail->pre;
	tail->pre->next = phead;
	free(tail);
	tail = NULL;
}

void DLPushFront(DLNode* phead, DLTDataType x)
{
	assert(phead);

	DLNode* newnode = DLCreateNode(x);

	newnode->next = phead->next;
	phead->next->pre = newnode;
	newnode->pre = phead;
	phead->next = newnode;
}

void DLPopFront(DLNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	DLNode* cur = phead->next;
	phead->next = cur->next;
	cur->next->pre = phead;
	free(cur);
	cur = NULL;
}

DLNode* DLFind(DLNode* phead, DLTDataType x)
{
	assert(phead);

	DLNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void DLInsert(DLNode* pos, DLTDataType x)
{
	assert(pos);
	//如果pos位置强行传入哨兵节点，那么在pos之前插入就相当于是尾插

	DLNode* pospre = pos->pre;
	DLNode* newnode = DLCreateNode(x);

	pospre->next = newnode;
	newnode->pre = pospre;
	newnode->next = pos;
	pos->pre = newnode;
}

void DLErase(DLNode* pos)
{
	assert(pos);

	DLNode* pospre = pos->pre;
	DLNode* posnext = pos->next;

	pospre->next = posnext;
	posnext->pre = pospre;
	free(pos);
	pos = NULL;
}

void DLDestroy(DLNode* phead)
{
	assert(phead);

	DLNode* cur = phead->next;
	while (cur != phead)
	{
		DLNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	printf("销毁完成！\n");
}