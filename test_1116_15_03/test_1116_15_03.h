#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLNDataType;

//������
typedef struct SListNode
{
	int value;
	struct SListNode* next;
}SLNode;

void SLTPrint(SLNode* phead);
//��ӡ����,phead��һ���ṹ��ָ��ָ������ĵ�һ��Ԫ�أ��洢�ľ��ǵ�һ��Ԫ�صĵ�ַ
void SLTPushBack(SLNode* phead, SLNDataType x);
//�����β��
//1��û�нڵ�����
// 
//2���нڵ�����
void SLTPushFront(SLNode* phead, SLNDataType x);
//�����ͷ��
