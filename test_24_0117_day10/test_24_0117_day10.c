#include <stdio.h>

//33. ËÑË÷Ğı×ªÅÅĞòÊı×é
int search(int* nums, int numsSize, int target)
{
    if (numsSize == 0)
    {
        return -1;
    }
    if (numsSize == 1)
    {
        return nums[0] == target ? 0 : -1;
    }
    int left = 0, right = numsSize - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[0] <= nums[mid])
        {
            if (nums[0] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[numsSize - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}