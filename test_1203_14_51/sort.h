#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

void Print(int* a, int n);
void Swap(int* p1, int* p2);

// ֱ�Ӳ�������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);
void SelectSort_2(int* a, int n);
//������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);
//��������
void QuickSort1(int* a, int start, int end);
