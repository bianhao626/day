#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//int cmp(const void* p1, const void* p2)
//{
//	return ((int*)p1)[0] - ((int*)p2)[0];
//}

//排序506. 相对名次
/*
int cmp(const void* p1, const void* p2)
{
    return ((int*)p1)[0] - ((int*)p2)[0];
}
char* medal[] = { "Gold Medal","Silver Medal","Bronze Medal" };
char** findRelativeRanks_1(int* score, int scoreSize, int* returnSize)
{
    char** ret = (char**)malloc(sizeof(char*) * scoreSize);
    *returnSize = scoreSize;

    int arr[scoreSize][2];//力扣中C99标准可以这样定义数组
    for (int i = 0; i < scoreSize; i++)
    {
        arr[i][0] = -score[i];
        arr[i][1] = i;
    }
    qsort(arr, scoreSize, sizeof(arr[0]), cmp);

    for (int i = 0; i < scoreSize; i++)
    {
        if (i < 3)
        {
            ret[arr[i][1]] = medal[i];
        }
        else
        {
            ret[arr[i][1]] = (char*)malloc(sizeof(char) * 8);
            sprintf(ret[arr[i][1]], "%d", i + 1);
        }
    }
    return ret;
}
*/
/*
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
char** findRelativeRanks_2(int* score, int scoreSize, int* returnSize)
{
    char** ret = (char**)malloc(scoreSize * sizeof(char*));
    (*returnSize) = scoreSize;
    for (int i = 0; i < scoreSize; i++)
    {
        ret[i] = (char*)malloc(sizeof(char) * 13);
    }
    int* temp = (int*)malloc(sizeof(int) * scoreSize);
    memcpy(temp, score, sizeof(int) * scoreSize);
    qsort(temp, scoreSize, sizeof(int), cmp);
    for (int i = 0; i < scoreSize; i++)
    {
        for (int j = 0; j < scoreSize; j++)
        {
            if (score[i] == temp[j])
            {
                if (j == scoreSize - 1)
                {
                    sprintf(ret[i], "%s", "Gold Medal");
                }
                else if (j == scoreSize - 2)
                {
                    sprintf(ret[i], "%s", "Silver Medal");
                }
                else if (j == scoreSize - 3)
                {
                    sprintf(ret[i], "%s", "Bronze Medal");
                }
                else
                {
                    sprintf(ret[i], "%d", scoreSize - j);
                }
            }
        }
    }
    return ret;
}
*/

//排序561. 数组拆分
int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}
int arrayPairSum(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2)
    {
        sum += nums[i];
    }
    return sum;
}

int main()
{
    //int arr[3][2] = { {2,1},{3,2},{1,3} };
    //qsort(arr, 3, sizeof(arr[0]), cmp);
    //qsort排序二维数组的问题
    //C学习：qsort快排函数在二维数组中的灵活应用 - 来知晓的文章 - 知乎
    //https://zhuanlan.zhihu.com/p/423111731
    int arr[6] = {6, 2, 6, 5, 1, 2};
    printf("%d\n", arrayPairSum(arr, 6));
	return 0;
}