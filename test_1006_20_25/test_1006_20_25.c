#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
bool containsDuplicate(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	for (size_t i = 0; i < numsSize-1; i++)
	{
		if (nums[i] == nums[i + 1])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int nums[] = { 1,2,3,4 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	bool ret = containsDuplicate(nums, sz);

	printf("%d\n", ret);
	return 0;
}