#include <stdio.h>
#include <stdlib.h>
#include "test_1115_20_16.h"

void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;

}
void SLDestroy(SL* ps)
{
	if (ps->a != NULL)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = 0;
		ps->capacity = 0;
	}
}
void SLPushBack(SL* ps, SLDataType x)
{
	//尾插
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

	ps->a[ps->size] = x;
	ps->size++;
}
void SLPushFront(SL* ps, SLDataType x)
{

}
void SLPopBack(SL* ps)
{

}
void SLPopFront(SL* ps)
{

}
void SLPrint(SL* ps)
{
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}


void Test()
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

	SLPrint(&s1);
}
int main()
{
	Test();
	return 0;
}