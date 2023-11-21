#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int QDataType;
//链式结构实现队列--单链表
typedef struct QListNode
{
	//定义队列节点
	QDataType data;
	struct QListNode* next;
}QNode;

typedef struct Queue
{
	//定义队列规则
	QNode* front;
	QNode* rear;
	int size;
}Queue;

void QueueInit(Queue* q);
//结构体指针即可修改成员内容
//void QueueInit(QNode** front,QNode** rear);
//定义的时候是定义一个指针，想要修改指针就需要传指针的地址，所以需要二级指针


void QueueDestroy(Queue* q);
void QueuePush(Queue* q, QDataType x);
void QueuePop(Queue* q);

QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);

int QueueSize(Queue* q);
bool QueueEmpty(Queue* q);

