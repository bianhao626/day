#define _CRT_SECURE_NO_WARNINGS 1
#include "test_1116_15_03.h"


void Test1()
{
	SLNode* L1 = NULL;
	SLTPushBack(&L1, 1);
	SLTPushBack(&L1, 2);
	SLTPrint(L1);

	SLTPopBack(&L1);
	SLTPrint(L1);
}
void Test2()
{
	SLNode* L1 = NULL;
	SLTPushFront(&L1, 1);
	SLTPushFront(&L1, 2);
	SLTPrint(L1);

	SLTPopFront(&L1);
	SLTPrint(L1);

	SLTPopFront(&L1);
	SLTPrint(L1);
}
void Test3()
{
	SLNode* L1 = NULL;
	SLTPushBack(&L1, 1);
	SLTPushBack(&L1, 2);
	SLTPushBack(&L1, 3);
	SLTPushBack(&L1, 4);
	SLTPrint(L1);

	SLNode* pos = SLTFind(L1, 1);

	SLTInsert(&L1, pos, 11);
	SLTPrint(L1);

	//SLTErase(&L1, pos);
	//SLTPrint(L1);
}
void Test4()
{
	SLNode* L1 = NULL;
	SLTPushBack(&L1, 1);
	SLTPushBack(&L1, 2);
	SLTPushBack(&L1, 3);
	SLTPushBack(&L1, 4);
	SLTPrint(L1);

	SLTDestroy(&L1);
	SLTPrint(L1);
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();

	return 0;
}