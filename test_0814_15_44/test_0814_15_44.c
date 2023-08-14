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
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param nums int����һά����
 * @param numsLen int nums���鳤��
 * @return int����
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