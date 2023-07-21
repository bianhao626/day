#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for ( i = 1; i <= 100; i++)
//	{
//		if (i%10==9)
//		{
//			count += 1;
//		}
//		if (i/10==9)
//		{
//			count += 1;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	int i = 0;
//	scanf("%d", &i); 
//
//	int left = 0;
//	int right = len - 1;
//	int flag = 0;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid]>i)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < i)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标是%d", mid);
//			flag = 1;
//			break;
//		}
//
//	}
//	if (flag==0)
//	{
//		printf("没有找到！");
//	}
//	return 0;
//}

#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("------------\n");
	printf("---1.play---\n");
	printf("---0.exit---\n");
	printf("------------\n");
}
void game()
{
	int a = 0;
	int flag = 1;
	int ret = rand() % 100 + 1;
	do
	{
		printf("请输入您选择的数字:");
		scanf("%d", &a);
		if (a>ret)
		{
			printf("您输入的数字太大了\n");
		}
		else if (a<ret)
		{
			printf("您输入的数字太小了\n");
		}
		else
		{
			printf("恭喜您，猜对了！\n");
			flag = 0;
		}
	} while (flag);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("欢迎下次再玩！");
			break;
		default:
			printf("输入错误，请重新输入:");
			break;
		}

	} while (input);
	return 0;
}