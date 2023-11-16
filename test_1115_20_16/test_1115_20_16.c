#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_1115_20_16.h"

void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newCapacity);
		//���ԶԿս�������
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;//��ֹ����ʧ�ܰ�ԭ�ռ������
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
		//free����������ָ���ͷ�λ�ò���
		//�ڶ��־��ǶԿռ�ķ�����Խ��
		ps->a = NULL;
		ps->size = 0;
		ps->capacity = 0;
	}
}
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	//β��
	SLCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	//ͷ��
	SLCheckCapacity(ps);

	//ÿ�β���һ�����ݣ�����ÿ�ΰ�˳�������Ų��һ��λ�þͿ���
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

	//βɾ
	//���򲻽���ɾ��
	assert(ps->size > 0);
	ps->size--;
}
void SLPopFront(SL* ps)
{
	//ͷɾ
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
	SLInit(&s1);//��ַ��ʽ���ſ��Զ�˳�����в���

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
	//printf("1��β������");
}
int main()
{
	//Test1();
	//����Խ���һ�㶼���ᱨ��Խ��дһ��ᱨ��
	//Խ��дһ�����������ߵ�λ��дһЩ��־λ�����ݣ���Ҫ�Ǽ���λ��������û�б���д
	Test2();
	return 0;
}