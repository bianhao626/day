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
//	fputs("abcdef", pf);//先将代码放在输出缓冲区
//	printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
//	Sleep(10000);
//	printf("刷新缓冲区\n");
//	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
//	//注：fflush 在高版本的VS上不能使用了
//	printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
//	Sleep(10000);
//	fclose(pf);
//	//注：fclose在关闭文件的时候，也会刷新缓冲区
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
//	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
//	strcpy(tmp, src); //先拷贝一遍
//	strcat(tmp, src); //再连接一遍
//	return strstr(tmp, find) != NULL; //看看找不找得到
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
//int FindNum(int a[][3], int x, int y, int f) //第一个参数的类型需要调整
//{
//	//杨氏矩阵，一般左下角和右上角可以使用
//	int i = 0, j = y - 1; //从右上角开始遍历
//	while (j >= 0 && i < x)
//	{
//		if (a[i][j] < f) //比我大就向下
//		{
//			i++;
//		}
//		else if (a[i][j] > f) //比我小就向左
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
//				  {5, 7, 9} }; //一个示例
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
		printf("合法转换:%d\n", ret);
	}
	else
	{
		printf("非法转换:%d\n", ret);
	}
	return 0;
}