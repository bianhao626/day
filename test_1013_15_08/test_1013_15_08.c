#include <stdio.h>

//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 > *(int*)e2;
//}
//
//int thirdMax(int* nums, int numsSize)
//{
//    qsort(nums, numsSize, sizeof(nums[0]), cmp);
//    int ret = nums[numsSize - 1];
//    int count = 0;
//    for (int i = numsSize - 1; i >= 0; i--)
//    {
//        if (ret > nums[i])
//        {
//            ret = nums[i];
//            count++;
//            if (count == 2)
//            {
//                return ret;
//            }
//        }
//    }
//    return nums[numsSize - 1];
//}

int cmp(int* a, int* b)
{
    return *a - *b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int m = gSize, n = sSize;
    int count = 0;
    for (int i = 0, j = 0; i < m && j < n; i++, j++)
    {
        while (j < n && g[i] > s[j])
        {
            j++;
        }
        if (j < n)
        {
            count++;
        }
    }
    return count;
