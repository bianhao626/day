#include <stdio.h>
#include <stdlib.h>
void merge(int* A, int ALen, int m, int* B, int BLen, int n)
{
    int* arr = (int*)malloc(sizeof(int) * (m + n));
    int i = 0, j = 0, k = 0;
    while (i < ALen && j < BLen)
    {
        if (A[i] < B[j])
        {
            arr[k] = A[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = B[j];
            k++;
            j++;
        }
    }
    while (i != ALen)
    {
        arr[k++] = A[i++];
    }
    while (j != BLen)
    {
        arr[k++] = B[j++];
    }
    for (int i = 0; i < m + n; i++)
    {
        A[i] = arr[i];
    }
}