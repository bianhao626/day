#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] >= target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (nums[mid] < target)
    {
        mid++;
    }
    return mid;
}

int main()
{
    int nums[] = { 1,4,7,8 };
    int target = 9;
    int ret = searchInsert(nums, 4, target);
    printf("%d", ret);
    return 0;
}