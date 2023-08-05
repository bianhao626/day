#include "game.h"

void Initboard(char board[ROWS][COLS], int row, int col, char ch)
{
	for ( int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ch;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	printf("---------------------------------\n");
	for (int x = 0; x <= col; x++)
	{
		printf(" %d ", x);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------------\n");
}
void Setboard(char board[ROWS][COLS], int row, int col)
{
	int count = NUM;
	while (count)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}
	}
}

int Get(char board1[ROWS][COLS], int x, int y)
{
	return board1[x - 1][y - 1] + board1[x - 1][y] + board1[x - 1][y + 1]
		+ board1[x][y - 1] + board1[x][y + 1]
		+ board1[x + 1][y - 1] + board1[x + 1][y] + board1[x + 1][y + 1]
		- 8 * '0';
}
void DisplayNum(char board1[ROWS][COLS],char board2[ROWS][COLS],int x,int y)
{
	int count = Get(board1, x, y);
	if (count == 0)
	{
		board2[x][y] = ' ';
		for (int i = x-1; i <= x+1 ; i++)
		{
			for (int j = y-1 ; j <= y+1; j++)
			{
				if (board2[i][j] == '*' && i > 0 && i < 11 && j > 0 && j < 11)
				{
					DisplayNum(board1, board2, i, j);
				}
			}
		}
	}
	else
	{
		board2[x][y] = count + '0';
	}
}
int Judge(char board[ROWS][COLS], int row, int col)
{
	int Sum = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (board[i][j] == '*')
			{
				Sum++;
			}
		}
	}
	if (Sum == NUM)
	{
		return 1;
	}
	return 0;
}
void Find(char board1[ROWS][COLS], char board2[ROWS][COLS], int row, int col)
{
	int i, j;
	while (1)
	{
		printf("请输入您选择的坐标:");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			if (board1[i][j] == '1')
			{
				printf("您踩到地雷了！\n");
				Displayboard(board1, ROW, COL);
				break;
			}
			else
			{
				DisplayNum(board1,board2,i,j);
				Displayboard(board2, ROW, COL);
				int ret = Judge(board2, ROW, COL);
				if (ret)
				{
					printf("你赢了!\n");
					break;
				}

			}
		}
		else
		{
			printf("您输入的坐标错误！");
		}
	}
}