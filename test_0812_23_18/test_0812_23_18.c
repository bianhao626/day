#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);
	int size = pow(10, n) - 1;
	int arr[100000];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	for (size_t j = 0; j < size; j++)
	{
		printf("%d ", arr[j]);
	}
	return 0;
}

//#include <math.h>
//int* printNumbers(int n, int* returnSize)
//{
//	// write code here
//	*returnSize = pow(10, n) - 1;
//	int arr[100000];
//	for (int i = 0; i < *returnSize; i++)
//	{
//		arr[i] = (i + 1);
//	}
//	return arr;
//}

