#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//		case 1:b = 30;
//		case 2:b = 20;
//		case 3:b = 10;
//		default:b = 0;
//	}
//	return b;
//}
//
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	int ret = func(a);
//	printf("%d",ret);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for ( i = 1; i <101 ; i++)
//	{
//		if (i%3 == 0)
//		{
//			printf("%d ",i);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a, b, c;
//	int tmp = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a<b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a<c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b<c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

//int main()
//{
//	int n;
//	for ( n = 100; n < 201; n++)
//	{
//		int i = 2;
//		while (i<n)
//		{
//			if (n % i == 0)
//				break;
//			i++;
//		}
//		if (i==n)
//		{
//			printf("%d ", n);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int i;
//	for ( i = 1000; i <= 2000; i++)
//	{
//		if (i % 100 != 0 && i%4 == 0)
//		{
//			printf("%d ", i);
//		}
//		else if (i%400 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	if (a < b)
//	{
//		int c = b;
//		b = a;
//		a = c;
//	}
//	while (b != 0)
//	{
//		int tmp = a % b;
//		a = b;
//		b = tmp;
//	}
//	printf("%d", a);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for ( i = 1; i < 10; i++)
//	{
//		int j;
//		for ( j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { -12,-23,-22,-1,-55,-21,-14,-65,-88,-100 };
//	int i = 0;
//	for ( i = 0; i < 9; i++)
//	{
//		int tmp = arr[0];
//		if (tmp < arr[i + 1])
//		{
//			arr[0] = arr[i + 1];
//		}
//	}
//	printf("%d", arr[0]);
//	return 0;
//}

int main()
{
	int i;
	float sum1 = 0;
	float sum2 = 0;
	for ( i = 1; i <=100 ; i++)
	{
		if (i % 2 != 0)
		{
			sum1 += 1.0 / i;
		}
		else if (i % 2 == 0)
		{
			sum2 += 1.0 / i;
		}
	}
	printf("%f", sum1 - sum2);
	return 0;
}
