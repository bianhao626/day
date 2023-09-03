#include <stdio.h>
//int MoreThanHalfNum_Solution(int* numbers, int numbersLen)
//{
//    //该方法是暴力求解法
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
方法二类似争夺高低的做法
定义一个 flag，人数统计 count
每当有一个相同的阵营的人，则计数加一
当出现不同阵营的人时，则抵消一个也就是原来人数减一
这样的话就会出现如果原来人数减少为0，那么另一个阵营的人夺得旗帜，人数统计也开始重新记录
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