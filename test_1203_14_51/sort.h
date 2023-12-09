#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

void Print(int* a, int n);
void Swap(int* p1, int* p2);

// ÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);
//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

//—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);
void SelectSort_2(int* a, int n);
//∂—≈≈–Ú
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n);
//øÏÀŸ≈≈–Ú
void QuickSort1(int* a, int start, int end);
