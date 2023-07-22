#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void Mupmultiplication_table(int x)
//{
//	int i = 0;
//	for ( i = 1; i <= x; i++)
//	{
//		int j = 0;
//		for ( j = 1; j <= i; j++)
//		{
//			printf("%2d*%2d=%3d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	Mupmultiplication_table(input);
//
//	return 0;
//}

//void Exchange(int *a, int *b)
//{
//	int tmp = *b;
//	*b = *a;
//	*a = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d %d\n", a, b);
//	
//	Exchange(&a, &b);
//	printf("%d %d\n", a, b);
//	return 0;
//}

//void Judgment(int x)
//{
//	if (((x % 4 == 0)&&(x % 100 != 0))||(x % 400 == 0))
//	{
//		printf("是闰年！");
//	}
//	else
//	{
//		printf("不是闰年！");
//	}
//
//}
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	Judgment(year);
//
//	return 0;
//}

void Is_prime(int x)
{
	int i = 2;
	while (i < x)
	{
		if (x % i == 0)
		{
			break;
		}
		i++;
	}
	if (i == x)
	{
		printf("%d ", x);
	}
}

int main()
{
	int i = 0;
	for ( i = 100; i < 201; i++)
	{
		Is_prime(i);
	}

	return 0;
}