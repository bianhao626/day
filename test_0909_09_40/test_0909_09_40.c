#include <stdio.h>

int minCostClimbingStairs(int* cost, int costLen)
{
    int dpath[11];
    dpath[0] = dpath[1] = 0;
    for (int i = 2; i <= costLen; i++)
    {
        dpath[i] = (dpath[i - 1] + cost[i - 1]) > (dpath[i - 2] + cost[i - 2]) ? (dpath[i - 2] + cost[i - 2]) : (dpath[i - 1] + cost[i - 1]);
    }
    return dpath[costLen];
}
int main()
{
    int cost[10] = { 55,89,84,47,76,71,75,63,18,9 };
    int ret = minCostClimbingStairs(cost, 10);
    printf("%d", ret);
    return 0;
}
/*
* 动态规划
动态规划算法的基本思想是：将待求解的问题分解成若干个相互联系的子问题，先求解子问题，然后从这些子问题的解得到原问题的解；
对于重复出现的子问题，只在第一次遇到的时候对它进行求解，并把答案保存起来，让以后再次遇到时直接引用答案，不必重新求解。
动态规划算法将问题的解决方案视为一系列决策的结果.

具体做法：

step 1：可以用一个数组记录每次爬到第i阶楼梯的最小花费，然后每增加一级台阶就转移一次状态，最终得到结果。
step 2：（初始状态） 因为可以直接从第0级或是第1级台阶开始，因此这两级的花费都直接为0。
step 3：（状态转移） 每次到一个台阶，只有两种情况，要么是它前一级台阶向上一步，要么是它前两级的台阶向上两步，
因为在前面的台阶花费我们都得到了，因此每次更新最小值即可，转移方程为：dp[i]=min(dp[i−1]+cost[i−1],dp[i−2]+cost[i−2])。
*/