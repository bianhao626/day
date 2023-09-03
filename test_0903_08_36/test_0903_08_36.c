#include <stdio.h>
//int MoreThanHalfNum_Solution(int* numbers, int numbersLen)
//{
//    //�÷����Ǳ�����ⷨ
//    int nums[10001] = { 0 };
//    int max = 0;
//    int ret;
//    for (int i = 0; i < numbersLen; i++)
//    {
//        nums[numbers[i]] += 1;
//    }
//    for (int j = 1; j < 10001; j++)
//    {
//        if (nums[j] > max)
//        {
//            max = nums[j];
//            ret = j;
//        }
//    }
//    return ret;
//}

/*
��������������ߵ͵�����
����һ�� flag������ͳ�� count
ÿ����һ����ͬ����Ӫ���ˣ��������һ
�����ֲ�ͬ��Ӫ����ʱ�������һ��Ҳ����ԭ��������һ
�����Ļ��ͻ�������ԭ����������Ϊ0����ô��һ����Ӫ���˶�����ģ�����ͳ��Ҳ��ʼ���¼�¼
*/
int MoreThanHalfNum_Solution(int* numbers, int numbersLen)
{
    int count = 0;
    int flag = numbers[0];
    for (int i = 0; i < numbersLen; i++)
    {
        if (numbers[i] == flag)
        {
            count++;
        }
        else
        {
            if (count > 0)
            {
                count--;
            }
            else
            {
                flag = numbers[i];
                count = 1;
            }
        }
    }
    return flag;
}
int main()
{
    int nums[9] = { 1,2,3,2,2,2,5,4,2 };
    int ret = MoreThanHalfNum_Solution(nums, 9);
    printf("%d", ret);
    return 0;
}