#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
//#define N 10
//typedef struct Stack
//{
//	STDataType a[N];
//	int top; // ջ��
//}Stack;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);//��ʼ��ջ
void STDestroy(ST* pst);//����ջ

void STPush(ST* pst, STDataType x);//��ջ
void STPop(ST* pst);//��ջ

STDataType STTop(ST* pst);//ջ��Ԫ��
int STSize(ST* pst);//ջ����ЧԪ�ظ���
bool STEmpty(ST* pst);//ջ�Ƿ�Ϊ��