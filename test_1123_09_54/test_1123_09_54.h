#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
//���鷽ʽʵ�ֶѽṹ
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

//ʵ��С��--���ڵ��ֵС�ں��ӽڵ��ֵ
void HeapInit(Heap* hp);
void HeapDestroy(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
bool HeapEmpty(Heap* hp);