#include <stdio.h>

//size_t my_strlen(const char* a)
//{
//	//������
//	int count = 0;
//	while (*a++)
//	{
//		count++;
//	}
//	return count;
//}
//size_t my_strlen(const char* a)
//{
//	//�ݹ�
//	if (*a == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(a + 1);
//	}
//}
//size_t my_strlen(const char* a)
//{
//	//ָ��-ָ��
//	char* p = a;
//	while (*p)
//	{
//		p++;
//	}
//	return p - a;
//}
//int main()
//{
//	char* a = "abcdef";
//	size_t ret = my_strlen(a);
//	printf("%zu", ret);
//	return 0;
//}

void my_strcpy(char* dest, const char* src)
{
	while (*dest++ = *src++)
	{
	}
}
int main()
{
	char arr1[20] = "aaaaaa";
	char* arr2 = "abcdefghij";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}