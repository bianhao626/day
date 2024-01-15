#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void MergeSortNonR(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);

	int gap = 1;
	while (gap < n)
	{
		for (size_t i = 0; i < n; i += 2 * gap)
		{
			int start_1 = i, end_1 = i + gap - 1;
			int start_2 = i + gap, end_2 = i + 2 * gap - 1;

			//对边界进行控制
			if (end_1 >= n || start_2 >= n)
			{
				break;
			}
			if (end_2 >= n)
			{
				end_2 = n - 1;
			}

			size_t j = i;
			while (start_1 <= end_1 && start_2 <= end_2)
			{
				if (a[start_1] > a[start_2])
				{
					tmp[j++] = a[start_2++];
				}
				else
				{
					tmp[j++] = a[start_1++];
				}
			}
			while (start_1 <= end_1)
			{
				tmp[j++] = a[start_1++];
			}
			while (start_2 <= end_2)
			{
				tmp[j++] = a[start_2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end_2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int n)
{
	int min = 0, max = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int tmp = max - min + 1;
	int* count = (int*)calloc(tmp, sizeof(int));
	assert(count);
	for (size_t x = 0; x < n; x++)
	{
		count[a[x] - min]++;
	}
	int j = 0;
	for (size_t y = 0; y < tmp; y++)
	{
		while (count[y]--)
		{
			a[j++] = y + min;
		}
	}
}

int main()
{
	int a[12] = { 1,10,2,8,5,3,9,7,1,6,5,3 };
	//MergeSortNonR(a, 12);
	CountSort(a, 12);
	for (size_t i = 0; i < 12; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}