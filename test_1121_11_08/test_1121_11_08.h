#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int QDataType;
//��ʽ�ṹʵ�ֶ���--������
typedef struct QListNode
{
	//������нڵ�
	QDataType data;
	struct QListNode* next;
}QNode;

typedef struct Queue
{
	//������й���
	QNode* front;
	QNode* rear;
	int size;
}Queue;

void QueueInit(Queue* q);
//�ṹ��ָ�뼴���޸ĳ�Ա����
//void QueueInit(QNode** front,QNode** rear);
//�����ʱ���Ƕ���һ��ָ�룬��Ҫ�޸�ָ�����Ҫ��ָ��ĵ�ַ��������Ҫ����ָ��


void QueueDestroy(Queue* q);
void QueuePush(Queue* q, QDataType x);
void QueuePop(Queue* q);

QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);

int QueueSize(Queue* q);
bool QueueEmpty(Queue* q);

