#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DLTDataType;

//��ͷ˫��ѭ������
typedef struct DListNode
{
	DLTDataType val;
	struct DListNode* pre;
	struct DListNode* next;
}DLNode;

DLNode* InitDL();//��ʼ��˫��ѭ������
void DLPrint(DLNode* phead);//��ӡ˫��ѭ������

DLNode* DLCreateNode(DLTDataType x);//����ͷ�ڵ�

void DLPushBack(DLNode* phead, DLTDataType x);//β��
void DLPopBack(DLNode* phead);//βɾ

void DLPushFront(DLNode* phead, DLTDataType x);//ͷ��
void DLPopFront(DLNode* phead);//ͷɾ

DLNode* DLFind(DLNode* phead, DLTDataType x);//����

void DLInsert(DLNode* pos, DLTDataType x);//˫������pos���루ǰ��Ϊ����
void DLErase(DLNode* pos);//˫������posɾ��

void DLDestroy(DLNode* phead);//���������