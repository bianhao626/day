#include "game.h"

//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int arr2[] = { 11,12,12,23,34,77,88,99,55,65 };
//	int len = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < len; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (int j = 0; j < len; j++)
//	{
//		printf("%d ", arr1[j]);
//	}
//	printf("\n");
//	for (int x = 0; x < len; x++)
//	{
//		printf("%d ", arr2[x]);
//	}
//	return 0;
//}



void menu()
{
	printf("-----------------\n");
	printf("----扫雷游戏-----\n");
	printf("---1.开始游戏----\n");
	printf("---0.退出游戏----\n");
	printf("-----------------\n");
}

void Game()
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};

	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	
	
	Setboard(mine, ROW, COL);
	Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	
	Find(mine, show, ROW, COL);
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
			Game();
			break;
		case 0:
			printf("欢迎下次再玩！\n");
			break;
		default:
			printf("选择有误，请重新选择！\n");
			break;
		}
	} while (input);

	return 0;
}