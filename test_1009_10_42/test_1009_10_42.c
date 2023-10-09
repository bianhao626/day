#include <stdio.h>
#include <stdlib.h>

//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int missingNumber(int* nums, int numsSize)
//{
//	qsort(nums, numsSize, sizeof(int), cmp);
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] != i)
//		{
//			return i;
//		}
//	}
//	return numsSize;
//}
/*36ms、7.7MB*/

int missingNumber(int* nums, int numsSize)
{
    int* hash = (int*)calloc(numsSize + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i]] = 1;
    }
    for (int i = 0; i < numsSize + 1; i++)
    {
        if (hash[i] != 1)
        {
            return i;
        }
    }
    return numsSize;
}
//哈希表的方式就是用空间换时间

int main()
{
	int nums[3] = { 3,0,1 };
	int ret = missingNumber(nums, 3);
	printf("%d", ret);
	return 0;
}

