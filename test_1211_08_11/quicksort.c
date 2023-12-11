#include "quicksort.h"
#include "stack.h"

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

	QuickSort2(a, 0, key - 1);
	QuickSort2(a, key + 1, end);
}

int PartSort1(int* a, int start, int end)
{
	int midi = GetMidi(a, start, end);
	Swap(&a[start], &a[midi]);

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

	return left;
}
int PartSort2(int* a, int start, int end)
{
	int midi = GetMidi(a, start, end);
	Swap(&a[start], &a[midi]);

	int key = a[start];
	int hole = start;
	while (start < end)
	{
		while (start < end && a[end] >= key)
		{
			end--;
		}
		a[hole] = a[end];
		hole = end;
		while (start < end && a[start] <= key)
		{
			start++;
		}
		a[hole] = a[start];
		hole = start;
	}
	a[hole] = key;
	return hole;
}
int PartSort3(int* a, int start, int end)
{
	int midi = GetMidi(a, start, end);
	Swap(&a[start], &a[midi]);

	int key = start;
	int pre = start;
	int cur = pre + 1;
	while (cur <= end)
	{
		if (a[cur] < a[key])
		{
			pre++;
			Swap(&a[pre], &a[cur]);
		}
		cur++;
	}
	Swap(&a[pre], &a[key]);
	return pre;
}
void QuickSort(int* a, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int hole = PartSort3(a, start, end);
	QuickSort(a, 0, hole - 1);
	QuickSort(a, hole + 1, end);
}


//非递归实现快排
void QuickSortNonR(int* a, int start, int end)
{
	ST s;
	STInit(&s);
	STPush(&s, end);
	STPush(&s, start);

	while (!STEmpty(&s))
	{
		int left = STTop(&s);
		STPop(&s);
		int right = STTop(&s);
		STPop(&s);

		int key = PartSort3(a, left, right);
		if (right > key+1)
		{
			STPush(&s, right);
			STPush(&s, key + 1);
		}
		if (left < key-1)
		{
			STPush(&s, key - 1);
			STPush(&s, left);
		}
	}

	STDestroy(&s);
}


void _MergeSort(int* a, int start, int end, int* tmp)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	_MergeSort(a, start, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	//归并逻辑
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	int i = start;
	while (start1 <= end1 && start2 <= end2)
	{
		if (a[start1] > a[start2])
		{
			tmp[i++] = a[start2++];
		}
		else
		{
			tmp[i++] = a[start1++];
		}
	}
	while (start1 <= end1)
	{
		tmp[i++] = a[start1++];
	}
	while (start2 <= end2)
	{
		tmp[i++] = a[start2++];
	}
	memcpy(a + start, tmp + start, sizeof(int) * (end - start + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, 0, n-1, tmp);

	free(tmp);
}