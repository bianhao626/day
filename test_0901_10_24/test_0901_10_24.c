#include <stdio.h>
//int singleNumber(int* nums, int numsSize)
//{
//    //��������˼��
//    //������ͬ�������������õ�����Ϊ0
//    //������ͬ�������������õ�������Ϊ0
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
* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
*
*
* @param str string�ַ��� ���жϵ��ַ���
* @return bool������
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