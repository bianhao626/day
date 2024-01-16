#include <stdio.h>
#include <stdlib.h>

//1480. 一维数组的动态和
int* runningSum_1(int* nums, int numsSize, int* returnSize)
{
    int* ans = (int*)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    ans[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        ans[i] = nums[i] + ans[i - 1];
    }
    return ans;
}

int* runningSum_2(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    for (int i = 1; i < numsSize; i++)
    {
        nums[i] += nums[i - 1];
    }
    return nums;
}

//35. 搜索插入位置
int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    int mid = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    if (nums[mid] < target)
    {
        return mid + 1;
    }
    return mid;
}

int main()
{
    int nums[4] = { 1,3,5,6 };
    printf("%d\n", searchInsert(nums, 4, 0));
    return 0;
}