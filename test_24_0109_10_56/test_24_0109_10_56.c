#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//面试题 01.02. 判定是否互为字符重排
bool CheckPermutation_1(char* s1, char* s2)
{
    //哈希表的方式
    int tmp[26] = { 0 };
    while (*s1)
    {
        tmp[*(s1)-'a'] += 1;
        s1++;
    }
    while (*s2)
    {
        tmp[*(s2)-'a'] -= 1;
        if (tmp[*(s2)-'a'] == -1)
        {
            return false;
        }
        s2++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (tmp[i] == 1)
        {
            return false;
        }
    }
    return true;
}

int cmp(const void* p1, const void* p2)
{
    return *(char*)p1 - *(char*)p2;
}
bool CheckPermutation_2(char* s1, char* s2)
{
    //排序的方式
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    if (n1 != n2)
    {
        return false;
    }

    qsort(s1, n1, sizeof(char), cmp);
    qsort(s2, n2, sizeof(char), cmp);

    return strcmp(s1, s2) == 0;
}

//面试题 01.04. 回文排列
bool canPermutePalindrome(char* s)
{
    //哈希表
    int tmp[128] = { 0 };
    while (*s)
    {
        tmp[*s] += 1;
        s++;
    }
    int count = 0;
    for (int i = 0; i < 128; i++)
    {
        if (tmp[i] % 2 == 1)
        {
            count++;
        }
        if (count >= 2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char ch[] = "aab";
    bool n = canPermutePalindrome(ch);
    printf("%d\n", n);
    return 0;
}