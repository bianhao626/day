#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

void Print(int* a, int n);
void Swap(int* p1, int* p2);

//快速排序
void QuickSort1(int* a, int start, int end);
void QuickSort2(int* a, int start, int end);

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int start, int end);
// 快速排序挖坑法
int PartSort2(int* a, int start, int end);
// 快速排序前后指针法
int PartSort3(int* a, int start, int end);
void QuickSort(int* a, int start, int end);