#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLNDateType;

//单链表--无头单向不循环链表
typedef struct SListNode
{
	int value;
	struct SListNode* next;
}SLNode;

void SLTPrint(SLNode* phead);
//打印链表,phead是一个结构体指针指向链表的第一个元素，存储的就是第一个元素的地址
void SLTPushBack(SLNode** pphead, SLNDateType x);
//链表的尾插
//1、没有节点的情况
//2、有节点的情况
//所以无论是第一种还是第二种，统一使用二级指针就可以
void SLTPushFront(SLNode** pphead, SLNDateType x);
//链表的头插
//因为需要改变最开始指向链表的地址，所以也需要二级指针


void SLTPopBack(SLNode** pphead);
//链表的尾删
//一前一后的两个指针进行，记录位置
void SLTPopFront(SLNode** pphead);
//链表的头删

SLNode* SLTFind(SLNode* phead, SLNDateType x);
//链表的查找

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDateType x);
//链表的任意位置插入
//插入是指在pos的前面的位置进行插入
void SLTErase(SLNode** pphead, SLNode* pos);
//链表的任意位置删除
//删除也是删除
void SLTDestroy(SLNode** pphead);
//链表的销毁
