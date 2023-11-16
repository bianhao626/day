#pragma once
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	//记录有效数据
	int capacity;
	//空间容量--如何扩容具体问题具体分析，一般选择是原来的二倍
}SL;

void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPushBack(SL* ps, SLDataType x);//顺序表的尾插
void SLPushFront(SL* ps, SLDataType x);//顺序表的头插
void SLPopBack(SL* ps);//顺序表的尾删
void SLPopFront(SL* ps);//顺序表的头删
void SLInsert(SL* ps, int pos, SLDataType x);//任意下标位置插入
void SLErase(SL* ps, int pos);//任意下标位置删除
void SLFind(SL* ps, SLDataType x);//顺序表查找操作，找到了返回下标，没找到就返回-1


void SLPrint(SL* ps);
void SLCheckCapacity(SL* ps);