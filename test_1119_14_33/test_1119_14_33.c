#include "test_1119_14_33.h"

void Test1()
{
	DLNode* DL1 = InitDL();
	DLPushBack(DL1, 1);
	DLPushBack(DL1, 2);
	DLPushBack(DL1, 3);
	DLPrint(DL1);

	DLPopBack(DL1);
	DLPrint(DL1);
}

void Test2()
{
	DLNode* DL2 = InitDL();
	DLPushBack(DL2, 1);
	DLPushBack(DL2, 2);
	DLPushBack(DL2, 3);
	DLPrint(DL2);

	DLPushFront(DL2, 4);
	DLPrint(DL2);

	DLPopFront(DL2);
	DLPrint(DL2);
}

void Test3()
{
	DLNode* DL3 = InitDL();
	DLPushBack(DL3, 1);
	DLPushBack(DL3, 2);
	DLPushBack(DL3, 3);
	DLPrint(DL3);

	DLNode* pos = DLFind(DL3, 3);
	
	DLInsert(pos, 55);
	DLPrint(DL3);

	DLErase(pos);
	DLPrint(DL3);

	pos = NULL;//传递是形参，所以为了不出现野指针，只能在此处置空
	DLDestroy(DL3);
	DL3 = NULL;//传递是形参，所以为了不出现野指针，只能在此处置空

}

int main()
{
	//Test1();
	//Test2();
	Test3();

	return 0;
}