#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//������ 01.02. �ж��Ƿ�Ϊ�ַ�����
bool CheckPermutation_1(char* s1, char* s2)
{
    //��ϣ��ķ�ʽ
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
    //����ķ�ʽ
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

//������ 01.04. ��������
bool canPermutePalindrome(char* s)
{
    //��ϣ��
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