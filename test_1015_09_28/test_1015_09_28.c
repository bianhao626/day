#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (size_t i = n; i > 0 ; i--)
//	{
//		for (size_t k = 0; k < i-1; k++)
//		{
//			printf(" ");
//		}
//		for (size_t j = 0; j < n; j++)
//		{
//			printf("A");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdlib.h> 
//int main()
//{
//	int n=3, m=3;
//	int** arr = (int**)malloc(sizeof(int) * n);
//	for (size_t i = 0; i < n; i++)
//	{
//		arr[i] = (int*)malloc(sizeof(int) * m);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <windows.h>
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//�Ƚ�����������������
//	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
//	Sleep(10000);
//	printf("ˢ�»�����\n");
//	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
//	//ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
//	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
//	Sleep(10000);
//	fclose(pf);
//	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int m, n, i, j, z, a, b = 0;
//	while (scanf("%d%d", &m, &n) != EOF)
//	{
//		for (a = m; a <= n; a++)
//		{
//			i = a / 100;
//			j = a / 10 - 10 * i;
//			z = a % 10;
//			if (a == i * i * i + j * j * j + z * z * z)
//			{
//				b++;
//				printf("%d ", a);
//			}
//		}
//		if (b == 0)
//		{
//			printf("no");
//		}
//	}
//	return 0;
//}

//#include <string.h>
//int findRound(const char* src, char* find)
//{
//	char tmp[256] = { 0 }; //��һ�������ռ佫ԭ�ַ�����������ԭ�ַ���
//	strcpy(tmp, src); //�ȿ���һ��
//	strcat(tmp, src); //������һ��
//	return strstr(tmp, find) != NULL; //�����Ҳ��ҵõ�
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "ddefab";
//	int ret = findRound(arr1, arr2);
//	printf("%d", ret);
//	return 0;
//}

//#include <stdio.h>
//int FindNum(int a[][3], int x, int y, int f) //��һ��������������Ҫ����
//{
//	//���Ͼ���һ�����½Ǻ����Ͻǿ���ʹ��
//	int i = 0, j = y - 1; //�����Ͻǿ�ʼ����
//	while (j >= 0 && i < x)
//	{
//		if (a[i][j] < f) //���Ҵ������
//		{
//			i++;
//		}
//		else if (a[i][j] > f) //����С������
//		{
//			j--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int a[][3] = { {1, 3, 5},
//				  {3, 5, 7},
//				  {5, 7, 9} }; //һ��ʾ��
//
//	if (FindNum(a, 3, 3, 2))
//	{
//		printf("It has been found!\n");
//	}
//	else
//	{
//		printf("It hasn't been found!\n");
//	}
//
//	return 0;
//}

#include <assert.h>
#include <ctype.h>
#include <limits.h>
enum state
{
	VALID,
	INVALID
}sta = INVALID;
int my_atoi(const char* str)
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	while (isspace(*str))
	{
		str++;
	}
	int flag = 1;
	if (*str == '+')
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	long long r = 0;
	while (*str)
	{
		if (isdigit(*str))
		{
			r = r * 10 + flag * (*str - '0');
			if (r > INT_MAX || r < INT_MIN)
			{
				if (flag == 1)
				{
					return INT_MAX;
				}
				else
				{
					return INT_MIN;
				}
			}
			str++;
		}
		else
		{
			return (int)r;
		}
	}
	sta = VALID;
	return (int)r;
}
int main()
{
	char arr[] = "-12345";
	int ret = my_atoi(arr);
	if (sta == VALID)
	{
		printf("�Ϸ�ת��:%d\n", ret);
	}
	else
	{
		printf("�Ƿ�ת��:%d\n", ret);
	}
	return 0;
}