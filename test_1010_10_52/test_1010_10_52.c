#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//void moveZeroes(int* nums, int numsSize)
//{
//    int i = 0, j = 0;
//    while (j < numsSize)
//    {
//        if (nums[j])
//        {
//            int tmp = nums[i];
//            nums[i] = nums[j];
//            nums[j] = tmp;
//            i++;
//        }
//        j++;
//    }
//}
//int main()
//{
//    int nums[] = { 4,2,4,0,0,3,0,5,1,0 };
//    moveZeroes(nums, 10);
//
//    return 0;
//}



int cmp(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    //ÅÅÐòºÍË«Ö¸Õë
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int) * fmin(nums1Size, nums2Size));

    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] > nums2[j])
        {
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            ret[(*returnSize)++] = nums1[i];
            i++;
            j++;
        }
    }
    return ret;
}