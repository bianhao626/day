#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DLTDataType;

//带头双向循环链表
typedef struct DListNode
{
	DLTDataType val;
	struct DListNode* pre;
	struct DListNode* next;
}DLNode;

DLNode* InitDL();//初始化双向循环链表
void DLPrint(DLNode* phead);//打印双向循环链表

DLNode* DLCreateNode(DLTDataType x);//创建头节点

void DLPushBack(DLNode* phead, DLTDataType x);//尾插
void DLPopBack(DLNode* phead);//尾删

void DLPushFront(DLNode* phead, DLTDataType x);//头插
void DLPopFront(DLNode* phead);//头删

DLNode* DLFind(DLNode* phead, DLTDataType x);//查找

void DLInsert(DLNode* pos, DLTDataType x);//双向链表pos插入（前插为例）
void DLErase(DLNode* pos);//双向链表pos删除

void DLDestroy(DLNode* phead);//链表的销毁