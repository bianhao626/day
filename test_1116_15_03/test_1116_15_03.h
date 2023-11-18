#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLNDateType;

//������--��ͷ����ѭ������
typedef struct SListNode
{
	int value;
	struct SListNode* next;
}SLNode;

void SLTPrint(SLNode* phead);
//��ӡ����,phead��һ���ṹ��ָ��ָ������ĵ�һ��Ԫ�أ��洢�ľ��ǵ�һ��Ԫ�صĵ�ַ
void SLTPushBack(SLNode** pphead, SLNDateType x);
//�����β��
//1��û�нڵ�����
//2���нڵ�����
//���������ǵ�һ�ֻ��ǵڶ��֣�ͳһʹ�ö���ָ��Ϳ���
void SLTPushFront(SLNode** pphead, SLNDateType x);
//�����ͷ��
//��Ϊ��Ҫ�ı��ʼָ������ĵ�ַ������Ҳ��Ҫ����ָ��


void SLTPopBack(SLNode** pphead);
//�����βɾ
//һǰһ�������ָ����У���¼λ��
void SLTPopFront(SLNode** pphead);
//�����ͷɾ

SLNode* SLTFind(SLNode* phead, SLNDateType x);
//����Ĳ���

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDateType x);
//���������λ�ò���
//������ָ��pos��ǰ���λ�ý��в���
void SLTErase(SLNode** pphead, SLNode* pos);
//���������λ��ɾ��
//ɾ��Ҳ��ɾ��
void SLTDestroy(SLNode** pphead);
//���������
