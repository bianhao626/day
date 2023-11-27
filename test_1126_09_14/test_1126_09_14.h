#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

typedef int HPDataType;
//数组方式实现堆结构
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

//实现小堆--父节点的值小于孩子节点的值
void HeapInit(Heap* hp);
void HeapDestroy(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
bool HeapEmpty(Heap* hp);

void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int size, int parent);

void HeapSort(HPDataType* a,int n);//堆排序