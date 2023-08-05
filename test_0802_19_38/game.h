#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2
#define NUM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initboard(char board[ROWS][COLS], int row, int col, char ch);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setboard(char board[ROWS][COLS], int row, int col);
void Find(char board1[ROWS][COLS], char board2[ROWS][COLS], int row, int col);