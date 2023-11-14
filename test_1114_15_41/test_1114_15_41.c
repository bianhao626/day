#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst++] = nums[src++];
		}
		else
		{
			src++;
		}
	}
	return dst;
}

int main()
{
	int nums[] = { 0,1,2,2,3,0,4,2 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = removeElement(nums, numsSize, 2);

	for (size_t i = 0; i < ret; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}