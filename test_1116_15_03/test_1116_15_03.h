#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLNDataType;

//单链表
typedef struct SListNode
{
	int value;
	struct SListNode* next;
}SLNode;

void SLTPrint(SLNode* phead);
//打印链表,phead是一个结构体指针指向链表的第一个元素，存储的就是第一个元素的地址
void SLTPushBack(SLNode* phead, SLNDataType x);
//链表的尾插
//1、没有节点的情况
// 
//2、有节点的情况
void SLTPushFront(SLNode* phead, SLNDataType x);
//链表额头插
