#include <stdio.h>
#include <stdlib.h>
//int FindGreatestSumOfSubArray(int* array, int arrayLen)
//{
//    //动态规划的问题
//    //注意：tmp数组存储的是截至到第i个元素的最大值，所以不需要考虑太复杂的子串如何划分
//    //只需要考虑如何得到到某个元素的最大值即可
//    int* tmp =(int*)malloc(sizeof(int) * arrayLen);
//    tmp[0] = array[0];
//    int max = array[0];
//    for (int i = 1; i < arrayLen; i++)
//    {
//        tmp[i] = (tmp[i - 1] + array[i]) > array[i] ? (tmp[i - 1] + array[i]) : array[i];
//        if (tmp[i] > max) {
//            max = tmp[i];
//        }
//    }
//    return max;
//}

int FindGreatestSumOfSubArray(int* array, int arrayLen)
{
    int sum = 0;
    int max = array[0];
    for (size_t i = 0; i < arrayLen; i++)
    {
        sum = (sum + array[i]) > array[i] ? (sum + array[i]) : array[i];
        max = sum > max ? sum : max;
    }
    return max;
}
int main()
{
    int nums[] = { 1,-2,3,10,-4,7,2,-5 };
    int len = sizeof(nums) / sizeof(nums[0]);
    int ret = FindGreatestSumOfSubArray(nums, len);
    printf("%d", ret);
    return 0;
}
/*
方法1：连续的子数组，即数组中从i下标到j下标（0<=i<=j<数组长度）的数据，想要获得所有的子数组和，
可以通过暴力法，两次循环获得，但时间复杂度为O(n^2)，效率不高。

方法2：动态规划，设动态规划列表 dp，dp[i] 代表以元素 array[i] 为结尾的连续子数组最大和。
状态转移方程： dp[i] = Math.max(dp[i-1]+array[i], array[i]);
具体思路如下：
1.遍历数组，比较 dp[i-1] + array[i] 和 array[i]的大小;
2.为了保证子数组的和最大，每次比较 sum 都取两者的最大值;
3.用max变量记录计算过程中产生的最大的连续和dp[i]；

方法3：我们可以简化动态规划，使用一个变量sum来表示当前连续的子数组和，
以及一个变量max来表示中间出现的最大的和。
*/