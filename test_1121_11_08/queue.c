#include "test_1121_11_08.h"

void QueueInit(Queue* q)
{
	assert(q);

	q->front = q->rear = NULL;
	q->size = 0;
}

void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->rear = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QDataType x)
{
	assert(q);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));

	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}

	newnode->data = x;
	newnode->next = NULL;

	if (q->rear == NULL)
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}

void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);

	QNode* del = q->front;
	q->front = q->front->next;
	free(del);
	q->size--;
	del = NULL;

	if (q->front == NULL)
	{
		q->rear = NULL;
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);

	return q->front->data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);

	return q->rear->data;
}

int QueueSize(Queue* q)
{
	assert(q);

	return q->size;
}
bool QueueEmpty(Queue* q)
{
	assert(q);

	return q->front == NULL;
}