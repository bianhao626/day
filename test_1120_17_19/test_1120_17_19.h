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
//	int top; // 栈顶
//}Stack;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);//初始化栈
void STDestroy(ST* pst);//销毁栈

void STPush(ST* pst, STDataType x);//入栈
void STPop(ST* pst);//出栈

STDataType STTop(ST* pst);//栈顶元素
int STSize(ST* pst);//栈中有效元素个数
bool STEmpty(ST* pst);//栈是否为空