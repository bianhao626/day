#include <stdio.h>
/*
һ�����������������������ֻ����һ�Σ����������ֶ����������Ρ�
��д�����ҳ�������ֻ����һ�ε����֡�
���ݷ�Χ�����鳤��2<=n<=1000,������ÿ�����Ĵ�С0<=val<=1000000
*/

//int* FindNumsAppearOnce(int* nums, int numsLen)
//{
//    //����λ����ķ���������
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
    //��ͳ˼���ǲ��ù�ϣ��ķ�ʽ
    //****���ǻ����ջ���������
    int hash[1000] = { 0 };//��̬������ʱ�����ִ����
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