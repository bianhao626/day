#include <stdio.h>
#include <stdlib.h>

//4. 寻找两个正序数组的中位数
//暴力法(时间复杂度是O(m+n))
double findMedianSortedArrays_1(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int* nums = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int i_1 = 0, i_2 = 0;
    int i = 0;
    while (i_1 < nums1Size && i_2 < nums2Size)
    {
        if (nums1[i_1] > nums2[i_2])
        {
            nums[i++] = nums2[i_2++];
        }
        else
        {
            nums[i++] = nums1[i_1++];
        }
    }
    if (i_1 == nums1Size)
    {
        while (i_2 < nums2Size)
        {
            nums[i++] = nums2[i_2++];
        }
    }
    else
    {
        while (i_1 < nums1Size)
        {
            nums[i++] = nums1[i_1++];
        }
    }
    int len = nums1Size + nums2Size;
    int k = len % 2;
    if (k == 0)
    {
        return (nums[len / 2] + nums[len / 2 - 1]) / 2.0;
    }
    else
    {
        return nums[len / 2];
    }
}

int main()
{
    int nums1[2] = { 1,2 };
    int nums2[2] = { 3,4 };
    double ret_1 = findMedianSortedArrays_1(nums1, 2, nums2, 2);
    printf("%lf\n", ret_1);
    return 0;
}