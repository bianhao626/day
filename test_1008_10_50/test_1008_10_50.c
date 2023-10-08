#include <stdio.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize)
{
    char** arr = (char**)malloc(sizeof(char*) * numsSize);
    *returnSize = 0;
    int i = 0;
    while (i < numsSize)
    {
        int low = i;
        i++;
        while (i < numsSize && nums[i] == nums[i - 1] + 1)
        {
            i++;
        }
        int high = i - 1;
        char* tmp = (char*)malloc(sizeof(char) * 25);
        sprintf(tmp, "%d", nums[low]);
        if (low < high)
        {
            sprintf((tmp + strlen(tmp)), "->");
            sprintf((tmp + strlen(tmp)), "%d", nums[high]);
        }
        arr[(*returnSize)++] = tmp;
    }
    return arr;
}

/*
* https://leetcode.cn/problems/summary-ranges/description/
* �����պÿ�����α�׼���뺯�� sprintf ���÷�
* sprintf �Ľ���--����̳�
* https://www.runoob.com/cprogramming/c-function-sprintf.html
* ��Ӧ sscanf �Ľ���--����̳�
* https://www.runoob.com/cprogramming/c-function-sscanf.html
*/
