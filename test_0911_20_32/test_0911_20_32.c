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
����ɼ����ǵģ����Ѿ�֪������֮ǰĳһ��Ĺɼ����

����Ҫ��϶������ڹɼ������������������׳���

���õ���ǰ��ν��"����"��������δ�����߼۸�

��ô�������δ���ļ۸��Ѿ������ˣ���ʵ����Ҫ�����Ҳ���ǣ�ÿһ�������ֵ

���Ƚϼ��õ������е������е��������������

��һ�죺��Сֵ8 ����8-8=0

�ڶ��죺��Сֵ8 ����9-8=1

�����죺��Сֵ2 ����2-2=0

�����죺��Сֵ2 ����4-2=2

�����죺��Сֵ2 ����10-2=8

�����죺��Сֵ1 ����1-1=0
*/