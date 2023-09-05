#include <stdio.h>
/*
一个整型数组里除了两个数字只出现一次，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
数据范围：数组长度2<=n<=1000,数组中每个数的大小0<=val<=1000000
*/

//int* FindNumsAppearOnce(int* nums, int numsLen)
//{
//    //采用位运算的方法来进行
//    int tmp = 0;
//    int ret[2] = { 0 };
//    for (int i = 0; i < numsLen; i++)
//    {
//        tmp ^= nums[i];
//    }
//    int p = 1;
//    while ((tmp & p) == 0)
//    {
//        p <<= 1;
//    }
//    int m = 0, n = 0;
//    for (int i = 0; i < numsLen; i++)
//    {
//        if ((nums[i] & p) == 0)
//        {
//            m ^= nums[i];
//        }
//        else
//        {
//            n ^= nums[i];
//        }
//    }
//    if (m > n)
//    {
//        ret[0] = n;
//        ret[1] = m;
//    }
//    else
//    {
//        ret[0] = m;
//        ret[1] = n;
//    }
//    return ret;
//}

int* FindNumsAppearOnce(int* nums, int numsLen)
{
    //传统思想是采用哈希表的方式
    //****但是会出现栈溢出的现象
    int hash[1000] = { 0 };//静态创建的时候会出现此情况
    int arr[2] = {0}, n = 0;
    for (size_t i = 0; i < numsLen; i++)
    {
        hash[nums[i]] += 1;
    }
    for (size_t j = 0; j < 1000; j++)
    {
        if (hash[j] == 1)
        {
            arr[n] = j;
            n++;
        }
    }
    if (arr[0] > arr[1])
    {
        n = arr[0];
        arr[0] = arr[1];
        arr[1] = n;
    }
    return arr;
}

int main()
{
    int nums[] = { 1,4,1,6 };
    int* ret;
    ret = FindNumsAppearOnce(nums, 4);
    for (size_t i = 0; i < 2; i++)
    {
        printf("%d ", ret[i]);
    }
    return 0;
}