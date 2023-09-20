#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t sz)
//{
//	assert(dest && src);
//	while (sz--)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		/*dest = (char*)dest + 1;*/
//		src = (char*)src + 1;
//	}
//}
//int main()
//{
//	int arr1[20] = { 0 };
//	int arr2[] = { 1,2,3,4,5,6 };
//
//	//memcpy函数拷贝的是字节
//	my_memcpy(arr1, arr2, 20);
//	return 0;
//}

void* my_memmove(void* dest, const void* src, size_t sz)
{
	assert(dest && src);
	if (dest < src)
	{
		for (size_t i = 0; i < sz; i++)
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else
	{
		while (sz--)
		{
			*((char*)dest + sz) = *((char*)src + sz);
		}
	}
}
int main()
{
	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr, arr + 2, 20);
	return 0;
}

int main()
{
	char* arr1 = "abcd";
	char arr2[] = "abcd";
	return 0;
}