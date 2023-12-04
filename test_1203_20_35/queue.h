#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef struct TreeNode* QDataType;
typedef struct QListNode
{
	QDataType data;
	struct QListNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);
void QueuePush(Queue* q, QDataType x);
void QueuePop(Queue* q);

QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);

int QueueSize(Queue* q);
bool QueueEmpty(Queue* q);