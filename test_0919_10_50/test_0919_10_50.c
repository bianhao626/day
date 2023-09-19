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
        if (arr[p].end >= intervals[i].end)//����
        {
            continue;
        }
        if (arr[p].end < intervals[i].start)//���ཻҲ������
        {
            p++;
            arr[p].start = intervals[i].start;
            arr[p].end = intervals[i].end;
        }
        else//�ཻ
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
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param intervals Interval��һά����
  * @param intervalsLen int intervals���鳤��
  * @return Interval��һά����
  * @return int* returnSize ������������
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
        if (arr[p].end >= intervals[i].end)//����
        {
            continue;
        }
        if (arr[p].end < intervals[i].start)//���ཻҲ������
        {
            p++;
            arr[p].start = intervals[i].start;
            arr[p].end = intervals[i].end;
        }
        else//�ཻ
        {
            arr[p].end = intervals[i].end;
        }
    }
    *returnSize = p + 1;
    return arr;
}
*/