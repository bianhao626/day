#include "test_1126_09_14.h"

void HeapInit(Heap* hp)
{
	assert(hp);

	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);

	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;

}
void AdjustUp(HPDataType* a, int child)
{
	//插入之后调整堆结构
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}

	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap* hp)
{
	//堆规定删除堆顶的数据
	assert(hp);
	assert(hp->size > 0);

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->a, hp->size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	return hp->a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}

bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}

//升序--建大堆
void HeapSort(HPDataType* a, int n)
{
	//建堆,插入建堆的方式
	//for (int  i = 0; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//建堆，向下调整的方式建堆
	for (int i = (n-1-1)/2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}