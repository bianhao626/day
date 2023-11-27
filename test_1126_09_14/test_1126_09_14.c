#include "test_1126_09_14.h"

void CreatNData()
{
	int n = 10000000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	assert(fin);
	for (int i = 0; i < n; i++)
	{
		int x = (rand()+i) % 10000000;
		fprintf(fin,"%d\n", x);
	}
	fclose(fin);
}

void PrintTopk(const char* file, int k)
{
	FILE* fin = fopen(file, "r");
	assert(fin);
	//建立小堆
	int* minheap = (int*)malloc(sizeof(int) * k);
	assert(minheap);
	for (int i = 0; i < k; i++)
	{
		fscanf(fin, "%d", &minheap[i]);
		AdjustUp(minheap, i);
	}
	int x = 0;
	while (fscanf(fin ,"%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}

	//打印出来
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}
	printf("\n");
	free(minheap);
	fclose(fin);
}

int main()
{
	int a[8] = { 4,6,2,1,5,8,9,2 };
	HeapSort(a, 8);

	//CreatNData();
	//PrintTopk("data.txt", 5);
	return 0;
}