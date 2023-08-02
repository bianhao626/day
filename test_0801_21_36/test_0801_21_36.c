#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>

//int main()
//{
//	int arr[] = { 1, 2, (3, 4), 5 };
//	printf("%d\n", sizeof(arr));
//	return 0;
//}

//int main()
//{
//	char acX[] = "abcdef";
//	char acY[] = { 'a','b','c','d','e','f' };
//	printf("%d  %d\n", sizeof(acX), sizeof(acY));
//	printf("%d  %d", strlen(acX), strlen(acY));
//	return 0;
//}

//int main()
//{
//    char str[] = "hello bit";
//    printf("%d %d\n", sizeof(str), strlen(str));
//    return 0;
//}

//void init(int* p,int k)
//{
//	int i;
//	for ( i = 0; i < k; i++)
//	{
//		*p++ = 0;
//	}
//}
//
//void my_print(int* p,int k)
//{
//	int i;
//	for (i = 0; i < k; i++)
//	{
//		printf("%d ", *p++);
//	}
//}
//
//void reverse(int* p,int k)
//{
//	int* q = p + k - 1;
//	while (q>p)
//	{
//		int tmp = *p;
//		*p = *q;
//		*q = tmp;
//		p++;
//		q--;
//	}
//}
//
//int main()
//{
//	int arr[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int input;
//	scanf("%d", &input);
//	switch (input)
//	{
//	case 1:
//		init(arr,len);
//		my_print(arr, len);
//		break;
//	case 2:
//		my_print(arr, len);
//		break;
//	case 3:
//		reverse(arr, len);
//		my_print(arr, len);
//		break;
//	default:
//		break;
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 12,44,1,56,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int len_1 = len;
//	while (len--)
//	{
//		for (int i = 0; i < len; i++)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				int tmp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = tmp;
//			}
//		}
//	}
//	for (int j = 0; j < len_1; j++)
//	{
//		printf("%d ", arr[j]);
//	}
//	return 0;
//}

#include "game.h"


void Menu()
{
	printf("----------------------\n");
	printf("-----三子棋游戏-------\n");
	printf("----选择1.开始游戏----\n");
	printf("----选择0.退出游戏----\n");
	printf("----------------------\n");
}

void Startgame()
{
	int ret;
	char qipan[ROW][COL] = {'0'};
	srand((unsigned int)time(NULL));
	//初始化棋盘
	Initqipan(qipan, ROW, COL);
	Displayqipan(qipan, ROW, COL);
	while (1)
	{
		//玩家下棋
		Playqipan(qipan, ROW, COL);
		Displayqipan(qipan, ROW, COL);
		//判断输赢
		ret = Check(qipan, ROW, COL);
		if (ret != 'D')
		{
			break;
		}
		//电脑下棋
		Computerqipan(qipan, ROW, COL);
		Displayqipan(qipan, ROW, COL);
		//判断输赢
		ret = Check(qipan, ROW, COL);
		if (ret != 'D')
		{
			break;
		}
	}
	if (ret=='*')
	{
		printf("您获得胜利！\n");
	}
	else if (ret=='#')
	{
		printf("您输了！\n");
	}
	else
	{
		printf("平局！\n");
	}
	
}

int main()
{
	int input;
	do
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Startgame();
			break;
		case 0:
			printf("欢迎下次继续!");
			break;
		default:
			printf("您的选择无效，请重新选择!\n");
			break;
		}
	} while (input);
	
	return 0;
}