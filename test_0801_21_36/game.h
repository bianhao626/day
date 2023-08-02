#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initqipan(char qipan[ROW][COL], int row, int col);
void Displayqipan(char qipan[ROW][COL], int row, int col);
void Playqipan(char qipan[ROW][COL], int row, int col);
void Computerqipan(char qipan[ROW][COL], int row, int col);
char Check(char qipan[ROW][COL], int row, int col);