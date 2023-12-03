#include "sort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void InsertSort(int* a, int n)
{
	//时间复杂度是 n^2，最好的时间复杂度是n
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n)
{
	//平均时间复杂度是n^1.3
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}







void BubbleSort(int* a, int n)
{
	//时间复杂度是 n^2，最好的时间复杂度是n
	//大数从前往后冒
	for (int i = 0; i < n-1; i++)
	{
		bool flag = false;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = true;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
}