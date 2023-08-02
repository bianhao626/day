#include "game.h"

void Initqipan(char qipan[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			qipan[i][j] = ' ';


		}
	}
}

void Displayqipan(char qipan[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", qipan[i][j]);
			if (j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i<row-1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void Playqipan(char qipan[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入您选择下的坐标(1-3)(1-3):");
		scanf("%d%d", &x, &y);
		if (x > ROW && x < 1 && y > COL && y < 1)
		{
			printf("您输入的坐标不正确，请重新选择!\n");
			continue;
		}
		else
		{
			if (qipan[x-1][y-1] == ' ')
			{
				qipan[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新选择!\n");
			}
		}
	}
	
}

void Computerqipan(char qipan[ROW][COL], int row, int col)
{
	int row_2, col_2;

	while (1)
	{
		row_2 = rand() % row;
		col_2 = rand() % col;
		if (qipan[row_2][col_2] == ' ')
		{
			qipan[row_2][col_2] = '#';
			break;
		}
	}
}

int Isfull(char qipan[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (qipan[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char Check(char qipan[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][0] != ' ')
		{
			return qipan[i][0];
		}
	}
	for ( j = 0; j < col; j++)
	{
		if (qipan[0][j] == qipan[1][j] && qipan[1][j] == qipan[2][j] && qipan[0][j] != ' ')
		{
			return qipan[0][j];
		}
	}
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[0][0] != ' ')
	{
		return qipan[1][1];
	}
	if (qipan[0][2] == qipan[1][1] && qipan[1][1] == qipan[2][0] && qipan[0][2] != ' ')
	{
		return qipan[1][1];
	}
	if (Isfull(qipan, ROW, COL)==1)
	{
		return 'C';
	}
	return 'D';
}