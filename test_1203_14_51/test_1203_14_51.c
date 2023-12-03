#include "sort.h"


void Test1()
{
	//≤Â»Î≈≈–Ú≤‚ ‘
	int arr1[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	InsertSort(arr1, len);
	Print(arr1, len);
	ShellSort(arr1, len);
	Print(arr1, len);
}
void Test2()
{
	//—°‘Ò≈≈–Ú≤‚ ‘
}
void Test3()
{
	//Ωªªª≈≈–Ú≤‚ ‘
	int arr3[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int len = sizeof(arr3) / sizeof(arr3[0]);
	BubbleSort(arr3, len);
	Print(arr3, len);
}

int main()
{
	Test1();

	Test3();
	return 0;
}