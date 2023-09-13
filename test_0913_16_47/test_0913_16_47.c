#include <stdio.h>
#include <string.h>
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}

//int main()
//{
//	int a[5] = { 5,4,3,2,1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}


typedef struct MyStruct
{
	char name[20];
	int age;
}S;
int cmp(const void* ptr1, const void* ptr2)
{
	return *(int*)ptr1 - *(int*)ptr2;
}
int cmp_struct(const void* ptr1, const void* ptr2)
{
	return strcmp(((S*)ptr1)->name, ((S*)ptr2)->name);
}
void swap(void* ptr1, void* ptr2, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		char tmp = *((char*)ptr1 + i);
		*((char*)ptr1 + i) = *((char*)ptr2 + i);
		*((char*)ptr2 + i) = tmp;
	}
}
void bubble(void* nums, size_t len, size_t size, int(*cmp)(const void* e1, const void* e2))
{
	for (size_t i = 0; i < len - 1; i++)
	{
		for (size_t j = 0; j < len - i -1; j++)
		{
			if (cmp((char*)nums + j * size, (char*)nums + (j + 1) * size) > 0)
			{
				swap((char*)nums + j * size, (char*)nums + (j + 1) * size, size);
			}
		}
	}
}

int main()
{
	int nums[] = { 8,5,21,5,6,2,1 };
	int len1 = sizeof(nums) / sizeof(nums[0]);
	bubble(nums, len1, sizeof(nums[0]), cmp);

	S arr[] = { {"王五",20},{"张三",18},{"白云",25} };
	int len2 = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, len2, sizeof(arr[0]), cmp_struct);
	return 0;
}