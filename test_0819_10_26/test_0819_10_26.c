#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int main()
//{
//    char ch[1000];
//    scanf("%s", ch);
//    int i, j;
//    int len = strlen(ch);
//    char tmp;
//    for (i = 0; i < len - 1; i++)
//    {
//        for (j = 0; j < len - i - 1; j++)
//        {
//            if (ch[j] > ch[j + 1])
//            {
//                tmp = ch[j];
//                ch[j] = ch[j + 1];
//                ch[j + 1] = tmp;
//            }
//        }
//    }
//    printf("%s", ch);
//    return 0;
//}

//int pivotIndex(int* nums, int numsSize)
//{
//    //此方法是暴力求解方法
//    int mid;
//    for (mid = 0; mid < numsSize; mid++)
//    {
//        int sumleft = 0;
//        int sumright = 0;
//        for (int i = 0; i < mid; i++)
//        {
//            sumleft += nums[i];
//        }
//        for (int i = mid + 1; i < numsSize; i++)
//        {
//            sumright += nums[i];
//        }
//        if (sumleft == sumright)
//        {
//            return mid;
//        }
//    }
//    return -1;
//}

//int pivotIndex(int* nums, int numsSize)
//{
//    int left = 0;
//    int sum = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (left * 2 + nums[i] == sum)
//        {
//            return i;
//        }
//        left += nums[i];
//    }
//    return -1;
//}
//int main()
//{
//    int num[] = { 1,7,3,6,5,6 };
//    int ret = pivotIndex(num, 6);
//    printf("%d", ret);
//    return 0;
//}

//int main()
//{
//    int hash[128] = { 0 };
//    char arr[500];
//    scanf("%s", arr);
//    int len = strlen(arr);
//
//    for (int i = 0; i < len; i++)
//    {
//        if (hash[arr[i]] == 0)
//        {
//            hash[arr[i]] = 1;
//        }
//    }
//    int count = 0;
//    for (int i = 0; i < 128; i++)
//    {
//        if (hash[i] == 1)
//        {
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}


int majorityElement(int* nums, int numsSize)
{
    //多数元素一般考虑方式，投票法也叫抢占高地
    int key = nums[0];
    int count = 0;
    for (size_t i = 0; i < numsSize; i++)
    {
        if (nums[i] == key)
        {
            count++;
        }
        else
        {
            count--;
            if (count < 0)
            {
                key = nums[i];
                count = 1;
            }
        }
    }
    return key;
}