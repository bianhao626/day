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
	printf("----ɨ����Ϸ-----\n");
	printf("---1.��ʼ��Ϸ----\n");
	printf("---0.�˳���Ϸ----\n");
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
			printf("��ӭ�´����棡\n");
			break;
		default:
			printf("ѡ������������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}