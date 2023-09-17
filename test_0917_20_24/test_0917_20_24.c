#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int my_strcmp(const char* p1, const char* p2)
//{
//	while (*p1 == *p2)
//	{
//		if (*p1 == '\0')
//		{
//			return 0;
//		}
//		p1++;
//		p2++;
//	}
//	if (*p1 > *p2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//int main()
//{
//	char* arr1 = "abc";
//	char* arr2 = "abc";
//	//int ret = strcmp(arr1, arr2);
//	//printf("%d", ret);
//
//	int ret = my_strcmp(arr1, arr2);
//	printf("%d", ret);
//	return 0;
//}


//char* my_strcat(char* p1, const char* p2)
//{
//	while (*p1 != '\0')
//	{
//		p1++;
//	}
//	while (*p1 = *p2)
//	{
//		p1++;
//		p2++;
//	}
//}
//int main()
//{
//	char arr1[20] = "aaa";
//	char* arr2 = "abc";
//	/*strcat(arr1, arr2);*/
//
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

#include <assert.h>
char* my_strstr(const char* p1, const char* p2)
{
	const char* tmp;
	const char* s1;
	const char* s2;
	assert(*p1 && *p2);
	if (*p2 == '\0')
	{
		return p1;
	}
	tmp = p1;
	while (*tmp)
	{
		s1 = tmp;
		s2 = p2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return tmp;
		}
		tmp++;
	}
	return NULL;
}
int main()
{
	char arr1[20] = "aaabcdef";
	char* arr2 = "abc";
	/*char* a = strstr(arr1, arr2);*/
	char* a = my_strstr(arr1, arr2);
	if (a == NULL)
	{
		printf("NO");
	}
	else
	{
		printf("%s",a);
	}
	return 0;
}