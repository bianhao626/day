#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

void Print(int* a, int n);
void Swap(int* p1, int* p2);

//��������
void QuickSort1(int* a, int start, int end);
void QuickSort2(int* a, int start, int end);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int start, int end);
// ���������ڿӷ�
int PartSort2(int* a, int start, int end);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int start, int end);
void QuickSort(int* a, int start, int end);