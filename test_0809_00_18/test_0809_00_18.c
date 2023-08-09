#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int keller = 0;
//	for (keller = 'A'; keller <= 'D'; keller++)
//	{
//		if ((keller != 'A') + (keller == 'C') + (keller == 'D') + (keller != 'D') == 3)
//		{
//			printf("%c", keller);
//		}
//	}
//		
//	return 0;
//}

//int main()
//{
//	int a, b, c, d, e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if ((a * b * c * d * e == 120) && (a + b + c + d + e == 15))
//								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//#define ROW 10
//int main()
//{
//	int arr[ROW][ROW];
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (j==0 || j==i)
//			{
//				arr[i][j] = 1;
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];;
//			}
//		}
//	}
//	for (int x = 0; x < ROW; x++)
//	{
//		for (int y = 0; y <= x; y++)
//		{
//			printf("%d ", arr[x][y]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a = 4;
//	return 0;
//}

//int check_sys()
//{
//	int i = 1;
//	return (*(char*)&i);
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int main()
//{
//    char a = -1;
//    signed char b = -1;
//    unsigned char c = -1;
//    printf("a=%d,b=%d,c=%d", a, b, c);
//    return 0;
//}

//int main()
//{
//    char a = -128;
//    printf("%u\n", a);
//    return 0;
//}

//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}

//int main()
//{
//    char str1[] = "hello bit.";
//    char str2[] = "hello bit.";
//    char* str3 = "hello bit.";
//    char* str4 = "hello bit.";
//    if (str1 == str2)
//        printf("str1 and str2 are same\n");
//    else
//        printf("str1 and str2 are not same\n");
//
//    if (str3 == str4)
//        printf("str3 and str4 are same\n");
//    else
//        printf("str3 and str4 are not same\n");
//
//    return 0;
//}

//#include <string.h>
//void revolve(char* left,int sz,int k)
//{
//	char* init = left;
//	while (k--)
//	{
//		left = init;
//		char tmp = *left;
//		char* left_1 = left + 1;;
//		for (int i = 0; i < sz - 1; i++)
//		{
//			*left = *left_1;
//			left++;
//			left_1++;
//		}
//		*left = tmp;
//	}
//}
//int main()
//{
//	char ch[] = "ABCDEF";
//	int sz = strlen(ch);
//	int k = 0;
//	scanf("%d", &k);
//	if (k<=sz)
//	{
//		revolve(ch, sz, k);
//	}
//	
//	printf("%s", ch);
//	return 0;
//}

#include <string.h>
int judge(char* ch1,char* ch2,int sz)
{
	char* init = ch1;
	int k = sz;
	while (k--)
	{
		ch1 = init;
		char tmp = *ch1;
		char* left_1 = ch1 + 1;;
		for (int i = 0; i < sz - 1; i++)
		{
			*ch1 = *left_1;
			ch1++;
			left_1++;
		}
		*ch1 = tmp;
		size_t ret = strcmp(init, ch2);
		if (ret == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char ch1[] = "ABCDEF";
	char ch2[] = "CDEFAH";
	int sz = strlen(ch1);

	int ret = judge(ch1, ch2, sz);
	if (ret == 1)
	{
		printf("符合旋转变换！");
	}
	else
	{
		printf("不符合旋转变换！");
	}
	return 0;
}