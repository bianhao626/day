#include "quicksort.h"

void Test1()
{
	//int arr1[] = { 3,2,6,8,4,6,0,9,5,7,1 };
	int arr1[] = { 6,1,2,7,9,3,6,4,5,10,8,6, };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	//QuickSort1(arr1, 0, len - 1);
	//QuickSort(arr1, 0, len - 1);
	QuickSortNonR(arr1, 0, len - 1);
	//MergeSort(arr1, len);
	Print(arr1, len);
}

int main()
{
	Test1();
	return 0;
}