#include "sort.h"


void Test1()
{
	//≤Â»Î≈≈–Ú≤‚ ‘
	int arr1[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	//InsertSort(arr1, len);
	//Print(arr1, len);
	ShellSort(arr1, len);
	Print(arr1, len);
}
void Test2()
{
	//—°‘Ò≈≈–Ú≤‚ ‘
	int arr2[] = { 13,2,6,8,4,6,0,9,5,7,1 };
	int len = sizeof(arr2) / sizeof(arr2[0]);
	//SelectSort(arr2, len);
	//Print(arr2, len);
	//SelectSort_2(arr2, len);
	//Print(arr2, len);
	HeapSort(arr2, len);
	Print(arr2, len);
}
void Test3()
{
	//√∞≈›≈≈–Ú≤‚ ‘
	int arr3[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int len = sizeof(arr3) / sizeof(arr3[0]);
	BubbleSort(arr3, len);
	Print(arr3, len);
}
void Test4()
{
	//Ωªªª≈≈–Ú≤‚ ‘
	//int arr4[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int arr4[] = { 6,1,2,7,9,3,6,4,5,10,8,6, };
	int len = sizeof(arr4) / sizeof(arr4[0]);
	QuickSort1(arr4, 0, len - 1);
	Print(arr4, len);
}

int main()
{
	//Test1();
	Test2();
	//Test3();
	//Test4();
	return 0;
}