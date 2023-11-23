#include "test_1123_09_54.h"

int main()
{
	int a[] = { 4,6,2,1,5,8,2,9 };
	Heap hp;
	HeapInit(&hp);
	for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		HeapPush(&hp, a[i]);
	}

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
	return 0;
}