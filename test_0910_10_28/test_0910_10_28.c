#include <stdio.h>
#include <stdlib.h>
//int FindGreatestSumOfSubArray(int* array, int arrayLen)
//{
//    //��̬�滮������
//    //ע�⣺tmp����洢���ǽ�������i��Ԫ�ص����ֵ�����Բ���Ҫ����̫���ӵ��Ӵ���λ���
//    //ֻ��Ҫ������εõ���ĳ��Ԫ�ص����ֵ����
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
����1�������������飬�������д�i�±굽j�±꣨0<=i<=j<���鳤�ȣ������ݣ���Ҫ������е�������ͣ�
����ͨ��������������ѭ����ã���ʱ�临�Ӷ�ΪO(n^2)��Ч�ʲ��ߡ�

����2����̬�滮���趯̬�滮�б� dp��dp[i] ������Ԫ�� array[i] Ϊ��β���������������͡�
״̬ת�Ʒ��̣� dp[i] = Math.max(dp[i-1]+array[i], array[i]);
����˼·���£�
1.�������飬�Ƚ� dp[i-1] + array[i] �� array[i]�Ĵ�С;
2.Ϊ�˱�֤������ĺ����ÿ�αȽ� sum ��ȡ���ߵ����ֵ;
3.��max������¼��������в���������������dp[i]��

����3�����ǿ��Լ򻯶�̬�滮��ʹ��һ������sum����ʾ��ǰ������������ͣ�
�Լ�һ������max����ʾ�м���ֵ����ĺ͡�
*/