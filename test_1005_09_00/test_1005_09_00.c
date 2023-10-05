#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

//int FindNumber(int* nums,int numLen)
//{
//	int* arr = (int*)calloc(sizeof(int) * 2);
//	int tmp = 0;
//	for (size_t i = 0; i < numLen; i++)
//	{
//		tmp ^= nums[i];
//	}
//	int mask = 1;
//	while ((tmp&mask) == 0)
//	{
//		mask << 1;
//	}
//	int a = 0, b = 0;
//	for (size_t i = 0; i < numLen; i++)
//	{
//		if ((nums[i] & mask) == 0)
//		{
//			a ^= nums[i];
//		}
//		else
//		{
//			b ^= nums[i];
//		}
//	}
//	arr[0] = a;
//	arr[1] = b;
//	return arr;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int* ptr1 = FindNumber(arr, sz);
//	return 0;
//}

//char* my_strncpy(char* dest, const char* src, size_t n)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (n && (*dest++ = *src++))
//	{
//		n--;
//	}
//	if (n)
//	{
//		while (--n)
//		{
//			*dest++ = '\0';
//		}
//	}
//	return ret;;
//}
//int main()
//{
//	char arr1[20] = "***********";
//	char arr2[] = "abcde";
//	/*strncpy(arr1, arr2, 7);*/
//	my_strncpy(arr1, arr2, 7);
//	printf("%s", arr1);
//	return 0;
//}


//char* my_strncat(char* dest, const char* src, size_t n)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (n--)
//	{
//		*dest++ = *src++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "***********";
//	char arr2[] = "abcde";
//	/*strncat(arr1, arr2, 4);*/
//	my_strncat(arr1, arr2, 3);
//
//	printf("%s", arr1);
//	return 0;
//}

//#include <stdlib.h>
//int main()
//{
//	int val;
//	char str[20];
//
//	strcpy(str, "98993489");
//	val = atoi(str);
//	printf("字符串值 = %s, 整型值 = %d\n", str, val);
//
//	strcpy(str, "romd.com");
//	val = atoi(str);
//	printf("字符串值 = %s, 整型值 = %d\n", str, val);
//	return 0;
//}

#include <math.h>
#include <stdlib.h>
int my_atoi(const char* str)
{
	assert(str);
	int* tmp = (int*)calloc(strlen(str), sizeof(int));
	int i = 0, ret = 0;
	if (tmp != NULL)
	{
		//判断第一个字符是否是数字
		if ((*str - 48) < 0 || (*str - 48) > 9)
		{
			return 0;
		}
		while ((*str - 48) >= 0 && (*str - 48) <= 9)
		{
			tmp[i++] = (*str - 48);
			str++;
		}
		for (size_t j = 0; j < i; j++)
		{
			ret += tmp[j] * (int)pow(10, i - 1 - j);
		}
		return ret;
	}
}
int main()
{
	int val;
	char str[20];
	strcpy(str, "12ron45678");
	val = my_atoi(str);
	/*
	* atoi函数无法检测中间的数字，执行逻辑如下：
	* 第一个字符为数字则进行记录直到不是数字为止
	* 第一个字符不是数字直接返回0
	*/

	printf("字符串值 = %s, 整型值 = %d\n", str, val);
	return 0;
}


//int main()
//{
//	char ch = '9';
//	printf("%d", ch-48);
//	return 0;
//}