#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//力扣--排序--242. 有效的字母异位词
//方案一
int cmp(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}

bool isAnagram_1(char* s, char* t)
{
    int len1 = strlen(s);
    int len2 = strlen(t);
    if (len1 != len2)
    {
        return false;
    }
    qsort(s, len1, sizeof(char), cmp);
    qsort(t, len2, sizeof(char), cmp);

    return strcmp(s, t) == 0;
}

//方案二
bool isAnagram_2(char* s, char* t)
{
    int hash[26] = { 0 };
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_s != len_t)
    {
        return false;
    }

    for (int i = 0; i < len_s; i++)
    {
        hash[s[i] - 'a']++;
    }
    for (int j = 0; j < len_t; j++)
    {
        hash[t[j] - 'a']--;
        if (hash[t[j] - 'a'] < 0)
        {
            return false;
        }
    }
    return true;
}

//力扣--排序--389. 找不同
//方案一
char findTheDifference_1(char* s, char* t)
{
    int hash[26] = { 0 };
    int len_s = strlen(s);
    int len_t = strlen(t);

    for (int i = 0; i < len_s; i++)
    {
        hash[s[i] - 'a']++;
    }
    for (int j = 0; j < len_t; j++)
    {
        hash[t[j] - 'a']--;
        if (hash[t[j] - 'a'] < 0)
        {
            return t[j];
        }
    }
    return ' ';
}

//方案二
char findTheDifference_2(char* s, char* t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);

    int sum_s = 0, sum_t = 0;
    for (int i = 0; i < len_s; i++)
    {
        sum_s += s[i];
    }
    for (int j = 0; j < len_t; j++)
    {
        sum_t += t[j];
    }
    return sum_t - sum_s;
}

int main()
{
    char s[] = "cat";
    char t[] = "catw";
    printf("%d\n", isAnagram_2(s, t));
    printf("%c\n", findTheDifference_2(s, t));
    return 0;
}