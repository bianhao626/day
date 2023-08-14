#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//    int n = 0;
//    int zcount = 0;
//    int fcount = 0;
//    float sum = 0;
//    scanf("%d", &n);
//    int arr[n];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int j = 0; j < n; j++)
//    {
//        if (arr[j] < 0)
//        {
//            fcount++;
//        }
//        else if (arr[j] > 0)
//        {
//            zcount++;
//            sum += arr[j];
//        }
//
//    }
//    if (sum == 0)
//    {
//        zcount = 1;
//    }
//    printf("%d %0.1f\n", fcount, sum / zcount);
//    return 0;
//}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param nums int整型一维数组
 * @param numsLen int nums数组长度
 * @return int整型
 */
int minNumberInRotateArray(int* nums, int numsLen)
{
    int left = 0;
    int right = numsLen - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else if (nums[mid] < nums[right])
        {
            right = mid;
        }
        else
        {
            right -= 1;
        }
    }
    return nums[left];
}