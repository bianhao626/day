#include "test_1120_17_19.h"

void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->capacity = 0;
	pst->top = -1;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->capacity = pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top+1 == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->top++;
	pst->a[pst->top] = x;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > -1);

	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > -1);

	return pst->a[pst->top];
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top + 1;
}

bool STEmpty(ST* pst)
{
	assert(pst);
	
	return pst->top == -1;
}