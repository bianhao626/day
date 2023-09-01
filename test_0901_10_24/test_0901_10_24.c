#include <stdio.h>
//int singleNumber(int* nums, int numsSize)
//{
//    //利用异或的思想
//    //两个相同的数异或操作，得到的数为0
//    //两个不同的数异或操作，得到的数不为0
//    int key = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        key = key ^ nums[i];
//    }
//    return key;
//}
//int main()
//{
//    int nums[5] = { 4,1,2,2,1 };
//    int ret = singleNumber(nums, 5);
//    printf("%d", ret);
//    return 0;
//}

/*
* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
*
*
* @param str string字符串 待判断的字符串
* @return bool布尔型
*/
bool judge(char* str)
{
    int len = strlen(str);
    int left = 0;
    int right = len - 1;
    int flag = 0;
    while (left < right)
    {
        if (str[left] == str[right])
        {
            left++;
            right--;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}