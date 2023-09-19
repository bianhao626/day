#include <stdio.h>
#include <string.h>
//char* solve(char* str)
//{
//    char tmp[1000] = { 0 };
//    int count = 0;
//    while (*str != '\0')
//    {
//        str++;
//        count++;
//    }
//    str--;
//    for (int i = 0; i < count; i++)
//    {
//        tmp[i] = *str--;
//    }
//    return tmp;
//}
//char* solve(char* str)
//{
//    int len = strlen(str);
//    printf("%d\n", len);
//    int left = 0, right = len - 1;
//    while (left < right)
//    {
//        char tmp = str[left];
//        str[left] = str[right];
//        str[right] = tmp;
//        left++;
//        right--;
//    }
//    return str;
//}
//int main()
//{
//    char str[] = "abcdefghijklmn";
//    char* str_solve = solve(str);
//    printf("%s", str_solve);
//    return 0;
//}


#include <stdlib.h>

struct Interval
{
    int start;
    int end;
};

int cmp(const void* a, const void* b)
{
    return (((struct Interval*)a)->start - ((struct Interval*)b)->start);
}
struct Interval* merge(struct Interval* intervals, int intervalsLen)
{
    if (intervalsLen == 0 || intervalsLen == 1)
    {
        return intervals;
    }
    struct Interval* arr = (struct Interval*)malloc(sizeof(struct Interval) * intervalsLen);
    qsort(intervals, intervalsLen, sizeof(struct Interval), cmp);

    arr[0].start = intervals[0].start;
    arr[0].end = intervals[0].end;

    int p = 0;
    int i;
    for (i = 1; i < intervalsLen; i++)
    {
        if (arr[p].end >= intervals[i].end)//包含
        {
            continue;
        }
        if (arr[p].end < intervals[i].start)//不相交也不包含
        {
            p++;
            arr[p].start = intervals[i].start;
            arr[p].end = intervals[i].end;
        }
        else//相交
        {
            arr[p].end = intervals[i].end;
        }
    }

    return arr;
}
int main()
{
    struct Interval arr[] = { {1,3}};
    struct Interval* arr1 = merge(arr, 1);
    return 0;
}



/**
 * struct Interval {
 *	int start;
 *	int end;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param intervals Interval类一维数组
  * @param intervalsLen int intervals数组长度
  * @return Interval类一维数组
  * @return int* returnSize 返回数组行数
  */
/*
#include <stdlib.h>
int cmp(const void* a, const void* b)
{
    return (((struct Interval*)a)->start - ((struct Interval*)b)->start);
}
struct Interval* merge(struct Interval* intervals, int intervalsLen, int* returnSize)
{
    if (intervalsLen == 0 || intervalsLen == 1)
    {
        *returnSize = intervalsLen;
        return intervals;
    }
    struct Interval* arr = (struct Interval*)malloc(sizeof(struct Interval) * intervalsLen);
    qsort(intervals, intervalsLen, sizeof(struct Interval), cmp);


    arr[0].start = intervals[0].start;
    arr[0].end = intervals[0].end;

    int p = 0;
    int i;
    for (i = 1; i < intervalsLen; i++)
    {
        if (arr[p].end >= intervals[i].end)//包含
        {
            continue;
        }
        if (arr[p].end < intervals[i].start)//不相交也不包含
        {
            p++;
            arr[p].start = intervals[i].start;
            arr[p].end = intervals[i].end;
        }
        else//相交
        {
            arr[p].end = intervals[i].end;
        }
    }
    *returnSize = p + 1;
    return arr;
}
*/