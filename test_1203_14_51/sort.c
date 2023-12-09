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

void SelectSort(int* a, int n)
{
	//单值选择排序
	int start = 0;
	while (start < n)
	{
		int mini = start;
		for (int i = start+1; i < n; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[start], &a[mini]);
		start++;
	}
}
void SelectSort_2(int* a, int n)
{
	//双值选择
	int start = 0, end = n - 1;
	while (start < end)
	{
		int mini = start, max = start;
		for (int i = start+1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		Swap(&a[start], &a[mini]);
		if (max == start)
		{
			max = mini;
		}
		Swap(&a[end], &a[max]);
		start++;
		end--;
	}
}
void AdjustDown(int* a, int n, int root)
{
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 <n && a[child+1] > a[child])
		{
			child++;
		}
		if (a[child] > a[root])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n-1-1)/2; i >= 0 ; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
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

void QuickSort1(int* a, int start, int end)
{
	// hoare版本
	if (start >= end)
	{
		return;
	}

	int left = start, right = end;
	int key = start;
	while (left < right)
	{
		while (a[right] >= a[key] && left < right)
		{
			right--;
		}
		while (a[left] <= a[key] && left < right)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	key = left;

	QuickSort1(a, 0, key - 1);
	QuickSort1(a, key + 1, end);
}


int GetMidi(int* a, int start, int end)
{
	int midi = (start + end) / 2;
	if (a[midi] < a[start])
	{
		if (a[midi] > a[end])
		{
			return midi;
		}
		else
		{
			if (a[start] > a[end])
			{
				return end;
			}
			else
			{
				return start;
			}
		}
	}
	else
	{
		if (a[start] > a[end])
		{
			return start;
		}
		else
		{
			if (a[midi] > a[end])
			{
				return end;
			}
			else
			{
				return midi;
			}
		}
	}
}
void QuickSort2(int* a, int start, int end)
{
	// hoare版本优化
	int midi = GetMidi(a, start, end);
	Swap(&a[start], &a[midi]);
	if (start >= end)
	{
		return;
	}

	int left = start, right = end;
	int key = start;
	while (left < right)
	{
		while (a[right] >= a[key] && left < right)
		{
			right--;
		}
		while (a[left] <= a[key] && left < right)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	key = left;

	QuickSort1(a, 0, key - 1);
	QuickSort1(a, key + 1, end);
}