#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_1115_20_16.h"

void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//扩容
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newCapacity);
		//可以对空进行扩容
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;//防止扩容失败把原空间给覆盖
		ps->capacity = newCapacity;
	}
}
void SLInit(SL* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;

}
void SLDestroy(SL* ps)
{
	assert(ps);

	if (ps->a != NULL)
	{
		free(ps->a);
		//free崩溃可能是指针释放位置不对
		//第二种就是对空间的访问有越界
		ps->a = NULL;
		ps->size = 0;
		ps->capacity = 0;
	}
}
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	//尾插
	SLCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	//头插
	SLCheckCapacity(ps);

	//每次插入一个数据，所以每次把顺序表往后挪动一个位置就可以
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[0] = x;
	ps->size++;
}
void SLPopBack(SL* ps)
{
	assert(ps);

	//尾删
	//空则不进行删除
	assert(ps->size > 0);
	ps->size--;
}
void SLPopFront(SL* ps)
{
	//头删
	assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[pos] = x;
	ps->size++;
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}
void SLFind(SL* ps, SLDataType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SLPrint(SL* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


void Test1()
{
	SL s1;
	SLInit(&s1);//传址方式，才可以对顺序表进行操作

	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPushBack(&s1, 6);
	SLPushBack(&s1, 7);
	SLPushFront(&s1, 20);
	SLPopBack(&s1);
	SLPopFront(&s1);

	SLPrint(&s1);
}
void Test2()
{
	SL s2;
	SLInit(&s2);

	SLPushBack(&s2, 1);
	SLPushBack(&s2, 2);
	SLPushBack(&s2, 3);
	SLPushBack(&s2, 4);
	SLPrint(&s2);
	SLInsert(&s2, 2, 40);
	SLPrint(&s2);
	SLErase(&s2, 3);
	SLPrint(&s2);
}

void menu()
{
	//printf("1、尾插数据");
}
int main()
{
	//Test1();
	//数组越界读一般都不会报错，越界写一般会报错
	//越界写一般是在数组后边的位置写一些标志位的数据，主要是检查该位置数据有没有被改写
	Test2();
	return 0;
}