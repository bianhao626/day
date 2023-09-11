#include <stdio.h>
int maxProfit(int* prices, int pricesLen)
{
    int min = *prices;
    int max = 0;
    for (int i = 0; i < pricesLen; i++)
    {
        min = min < prices[i] ? min : prices[i];
        max = max > (prices[i] - min) ? max : (prices[i] - min);
    }
    return max;
}

int main()
{
    int nums[] = { 8,9,2,4,10,1 };
    int ret = maxProfit(nums, 6);
    printf("%d", ret);
    return 0;
}
/*
假设股价是涨的，你已经知道今天之前某一天的股价最低

那你要买肯定就是在股价最低那天买进，今天抛出。

即得到当前所谓的"利润"（不包含未来更高价格）

那么如果整个未来的价格已经给你了，其实我们要计算的也就是：每一天的利润值

作比较即得到所有中的利润中的最大利润及所求数

第一天：最小值8 利润：8-8=0

第二天：最小值8 利润：9-8=1

第三天：最小值2 利润：2-2=0

第四天：最小值2 利润：4-2=2

第五天：最小值2 利润：10-2=8

第六天：最小值1 利润：1-1=0
*/